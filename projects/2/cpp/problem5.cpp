/**
 * project 2, problem 6b
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
const double tol = my_machine_epsilon * 1e8 ;

//const int N = 6;

// dimension of our square symmetric matrix
// a quick-and-dirtry loop to run the program for a set of N values
// for problem 5 we keep N to 6
for(int N=6; N<7; N++){



// initialize matrix A

//arma::mat A = arma::mat(N, N, arma::fill::eye);
//test with matrix A from problem 3{
int n = N + 1;
double h = 1.0/(double)n;

const double h2 = h*h;
const double a = -1/h2;
const double d = 2/h2;
mat A = create_symmetric_tridiagonal(N, a, d);



    // set a maximum number of iterations so we don't go on forever
    // using N^3 like in the course texbook
    const double max_iterations = N*N*N;
    // keep count of iterations
    int iterations = 0;
    //define and initialize R
    arma::mat R = arma::mat(N, N, arma::fill::eye);


    // find the largest (in absolute value) off diagonal element
    // start at element A[0][1], in the upper triangle of the symmetric matrix A
    int k=0;
    int l=1;
    double largest = max_offdiag_symmetric(A,k,l);


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

        // we use the same shorthand as in the textbook for the course
        double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
        a_kk = A.at(k,k);
        a_ll = A.at(l,l);
        
        A.at(k,k) = a_kk*c*c - 2*A.at(k,l)*c*s + a_ll*s*s; 
        A.at(l,l) = a_ll*c*c + 2*A.at(k,l)*c*s + a_kk*s*s;
        A.at(k,l) = 0.0;
        A.at(l,k) = 0.0;
        for(int i=0;i<N;i++){
            if(i!=k && i!=l){
                a_ik = A.at(i,k);
                a_il = A.at(i,l);
                A.at(i,k) = a_ik*c - a_il*s;
                A.at(k,i) = A.at(i,k);
                A.at(i,l) = a_il*c + a_ik*s;
                A.at(l,i) = A.at(i,l);
            }
        //update R 
        r_ik = R.at(i,k);
        r_il = R.at(i,l);  
        R.at(i,k) = r_ik*c - r_il*s;
        R.at(i,l) = r_il*c + r_ik*s;
        }

        //find indexes for largest off diagonal element again
        //which will update k and l
        largest = max_offdiag_symmetric(A,k,l);

        //increment iterations
        iterations = iterations + 1;
    }//end while




    cout << "Largest (in absolute value) superdiagonal element of A is: A["<< k << "][" << l <<"] = " << largest << endl << endl;
    cout << "Tolerance = " << tol << endl << endl;
    cout << "N = " << N << " " << "number of iterations = " << iterations << endl << endl;
    cout << A << endl;
    cout << R << endl;
}      
/**/
return 0;
}//:~ end main()
