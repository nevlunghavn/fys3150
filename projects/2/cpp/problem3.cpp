/**
 * project 2, problem 3
 */

#include <iostream>
#include <armadillo>
#include "utils.hpp"
#include "project2.hpp"

using namespace std;
using namespace arma;

int main(){

  // problem 3
  // define the constants
  // N = n - 1 => n = N + 1
  // N = 6 => n = 7
  // h = 1/n = 1/7 => h2 = h^2 = 1/49 
  const double h2 = 1.0E0/4.9E1;
  const double a = -1/h2;
  const double d = 2/h2;
  //const double e = a;

  // define the matrix A
  mat A = create_symmetric_tridiagonal(6, a, d);

  // print A to standard output to ensure it is correctly 
  // generated
  cout << "The matix A = " << endl;
  cout << endl;
  cout << A << endl;

  cout << endl;
  cout << "The analytical eigenvalues of A are: " << endl;
  cout << endl;
  std::vector<double> L = bb_eigenval(6,a,d);
  for(double elem : L){
    cout << scientific_format(elem) << endl;
  }



  // vector to hold eigenvalues
  vec eigval;
  // matrix to hold eigenvectors
  mat eigvec;
  // use Armadillo to find the eigenvalues and corresponding 
  // eigenvectors
  eig_sym(eigval, eigvec, A);
  cout << endl;
  cout << "The eigenvalues of A using Armadillo are:" << endl;
  cout << endl;
  for (double elem : eigval){
    cout << scientific_format(elem) << endl;
  }
  cout << endl;
  cout << "The corresponding eigenvectors using Armadillo are:" << endl;
  cout << endl;
  cout << eigvec << endl;

//test{
std::vector<double> V = bb_eigenvec(6,2);
for(double elem : V){
  cout << scientific_format(elem) << endl;
}
std::vector<double> V_normal = normalize_vec(V);
for(double elem : V_normal){
  cout << scientific_format(elem) << endl;
}
//test}
//   // mat A(4, 5, fill::randu);
//   // mat B(4, 5, fill::randu);
  
//   // cout << A << endl;
//   // cout << B << endl;
//   // cout << A.t() << endl;
//   // cout << A*B.t() << endl;
  

//   // // Print results
//   // std::cout << std::endl;
//   // std::cout << "a number: " << scientific_format(0.556443) << std::endl;
//   // std::cout << "another number: " << scientific_format(56434676) << std::endl;

// // h = 1/n = 1/7 => h2 = h^2 = 1/49 
// const double h2 = 1.0/49.0;
// const double a = -1/h2;
// const double d = 2/h2;
// const double e = a;
// mat M = create_tridiagonal(6, a, d, 3.14);
// cout << M << endl;
// mat L = create_symmetric_tridiagonal(6, a, d);
// cout << L << endl;
// // mat M = create_tridiagonal(6, a, d, e);
// // mat L = create_symmetric_tridiagonal(6, a, d);



// test bb_eigen_val

//std::vector<double> L = bb_eigen_val(6,a,d);
//cout << L[0] << endl;

  // for (int i=0;i<5;i++){
  //   cout << L[i] << endl;
  // }

//double arr[6] =  bb_eigen_val(a,d);

//cout << d + 2.0*a*std::cos(2*PI/(6+1)) << endl;
//cout << arr[0] << endl;

// std::vector<double> LL;
// for(int i=1; i<7; i++){
//   LL.push_back(d + 2.0*a*std::cos((double)i*PI/(6+1)));
// }
//LL.push_back(d + 2.0*a*std::cos(2*PI/(6+1)));
// cout << LL.size() << endl;
// cout << LL[0] << endl;




















/************************************************/
  return 0;
}
