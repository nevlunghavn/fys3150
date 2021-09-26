/**
 * project 2, problem 5
 * implements the Jacobi rotation algorithm as described 
 * in 
 * https://www.uio.no/studier/emner/matnat/fys/FYS3150/h21/forelesningsvideoer/cynap_fys3150_20210917_081622.mp4?vrtx=view-as-webpage
 * 
 * and
 * 
 * https://www.uio.no/studier/emner/matnat/fys/FYS3150/h21/forelesningsvideoer/cynap_fys3150_20210917_091644.mp4?vrtx=view-as-webpage
 * 
 */ 

#include <iostream>
#include <armadillo>
#include "utils.hpp"
#include "project2.hpp"

using namespace std;
using namespace arma;


int main(){

// my machine epsilon is 
const double my_machine_epsilon = 2.220446049250313e-16;
// set the tolerance. Smaller numbers are considered to be equal to zero.
const double tol = my_machine_epsilon * 1e15 ;
cout << "Tolerance = " << tol << endl << endl;
// dimension of our square symmetric matrix
const double N = 6;
// set a maximum number of iterations so we don't go on forever
// using N^3 like in the course texbook
const double max_iterations = N*N*N;
// keep count of iterations
int iterations = 0;

// initialize matrix A

//arma::mat A = arma::mat(N, N, arma::fill::eye);
//test with matrix A from problem 3{
int n = N + 1;
double h = 1.0/(double)n;

const double h2 = h*h;
const double a = -1/h2;
const double d = 2/h2;
mat A = create_symmetric_tridiagonal(N, a, d);
//}
//test{
//A.at(0,0) = 0.047937;
//A.at(1,1) = -0.434876;
//A.at(0,1) = 0.100506;
//A.at(1,0) = A.at(0,1);
//test}


// A.at(1,0) = std::sqrt(2);
// A.at(2,0) = 2;
// A.at(0,1) = std::sqrt(2);
// A.at(1,1) = 3;
// A.at(2,1) = std::sqrt(2);
// A.at(0,2) = A.at(2,0) ;
// A.at(1,2) = A.at(2,1);
cout << endl;
cout << "Matrix A = " << endl;
cout << A << endl;
cout << endl;

//define and initialize R
arma::mat R = arma::mat(N, N, arma::fill::eye);
cout << endl;
cout << "Matrix R = " << endl;
cout << R << endl;
cout << endl;


// find the largest (in absolute value) off diagonal element
// start at element A[0][1], in the upper triangle of the symmetric matrix A
int k=0;
int l=1;
double largest = max_offdiag_symmetric(A,k,l);
cout << "Largest (in absolute value) superdiagonal element of A is: A[";
cout << k << "][" << l <<"] = " << largest << endl << endl;

while (std::abs(A.at(k,l)) > tol && iterations < max_iterations) {

    //compute tau
    double tau;
    //define and compute tan(theta)
    double t;
    //define and compute cos(theta)
    double c;
    //define and compute sin(theta)
    double s;
    if(A.at(k,l) == 0){
        c = 1.0;
        s = 0.0;
        t = 0.0;
    }else{
        tau = (A.at(l,l) - A.at(k,k))/(2.0*A.at(k,l));
        if(tau > 0){
            t = 1.0/(tau + std::sqrt(1.0 + tau*tau));
        }else{
            t = -1.0/(-tau + std::sqrt(1.0 + tau*tau));
        }
        c = 1.0/std::sqrt(1.0+t*t);

        s = c*t;
    }

    //define and initialize S
    arma::mat S = arma::mat(N, N, arma::fill::eye);
    S.at(k,k) = c;
    S.at(k,l) = s;
    S.at(l,k) = -s;
    S.at(l,l) = c;
    cout << endl;
    cout << "Matrix S = " << endl;
    cout << S << endl;
    cout << endl;

    //transform current A matrix S^T A S by updating elements
    //this should be done by in place modification of the elements of A
    //rather than keeping copies of A
    //need to keep temp copies of few elements
    // double tmpA_kl = A.at(k,l);
    // double tmpA_ll = A.at(l,l);
    //test with Armadillo transpose and multiply{
    // cout << endl;
    // cout << "Matrix S transposed = " << endl;
    // cout << S.t() << endl;
    // cout << endl; 
    // cout << endl;
    // cout << "Matrix S^T A S = " << endl;
    // cout << S.t() * (A * S) << endl;
    // cout << endl; 
    //test}

    // we use the same shorthand as in the textbook for the course
    double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
    a_kk = A.at(k,k);
    a_ll = A.at(l,l);
     
    A.at(k,k) = a_kk*c*c - 2*A.at(k,l)*c*s + a_ll*s*s; 
    A.at(l,l) = a_ll*c*c + 2*A.at(k,l)*c*s + a_kk*s*s;
    A.at(k,l) = 0.0;
    A.at(l,k) = 0.0;
    cout << endl;
    cout << "Matrix A = " << endl;
    cout << A << endl;
    cout << endl;
    cout << "A_kl = A[" << k << "][" << l << "] = " << A.at(k,l) << endl;
    //update the off diagonal elements
    //save "old" elements that are used 
    //more than once in the loop

    for(int i=0;i<N;i++){
    //double tmpA_ik = A.at(i,k);
        if(i!=k && i!=l){
            a_ik = A.at(i,k);
            a_il = A.at(i,l);
            A.at(i,k) = a_ik*c - a_il*s;
            A.at(k,i) = A.at(i,k);
            A.at(i,l) = a_il*c + a_ik*s;
            A.at(l,i) = A.at(i,l);
        }

    cout << endl;
    cout << "Matrix S^T A S = " << endl;
    cout << A << endl;
    cout << endl;
    //update R 
    r_ik = R.at(i,k);
    r_il = R.at(i,l);  
    R.at(i,k) = r_ik*c - r_il*s;
    R.at(i,l) = r_il*c + r_ik*s;
    }

    //find indexes for largest off diagonal element again
    //which will update k and l
    double largest = max_offdiag_symmetric(A,k,l);
    cout << "Largest (in absolute value) superdiagonal element of A is: A["<< k << "][" << l <<"] = " << largest << endl << endl;

    //increment iterations
    iterations = iterations + 1;
}//end while

cout << "After " << iterations << " iterations: " << endl << endl;
cout << endl;
cout << "Matrix R = " << endl;
cout << R << endl<<endl;


/****/
return 0;
}//:~main()

