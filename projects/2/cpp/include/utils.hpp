// The bulk of the code here is taken from code samples shared
// at the course GitHub repository 
// See. https://github.com/anderkve/FYS3150


// First we add an "include guard". It ensures that this header file can 
// only end up being included *once* for the compilation of any given .cpp file
#ifndef __utils_hpp__  
#define __utils_hpp__

// Now we include headers we need
#include <armadillo>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>


// Below we give some function *declarations*.
// The function *definitions* (the actual code) 
// lives in utils.cpp


std::string scientific_format(double d, const int width=20, const int prec=10);
std::string scientific_format(const arma::vec& v, const int width=20, const int prec=10);

// // Create a tridiagonal matrix tridiag(a,d,e) of size n*n, 
// // from scalar input a, d, and e. That is, create a matrix where
// // - all n-1 elements on the subdiagonal have value a
// // - all n elements on the diagonal have value d
// // - all n-1 elements on the superdiagonal have value e
// arma::mat create_tridiagonal(int n, double a, double d, double e);
// // Create a symmetric tridiagonal matrix tridiag(a,d,a) of size n*n
// // from scalar input a and d.
// arma::mat create_symmetric_tridiagonal(int n, double a, double d);



arma::mat create_tridiagonal(const arma::vec& a, const arma::vec& d, const arma::vec& e);
arma::mat create_tridiagonal(int n, double a, double d, double e);
arma::mat create_symmetric_tridiagonal(int n, double a, double d);




#endif  // end of include guard __utils_hpp__