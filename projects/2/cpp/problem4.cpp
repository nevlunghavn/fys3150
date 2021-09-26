/**
 * project 2, problem 4
 */ 

#include <iostream>
#include <armadillo>
#include "utils.hpp"
#include "project2.hpp"

using namespace std;
using namespace arma;


int main(){


arma::mat A = arma::mat(4, 4, arma::fill::eye);
A.at(0,3) = 0.5;
A.at(3,0) = A.at(0,3);
A.at(1,2) = -0.7;
A.at(2,1) = A.at(1,2);
cout << endl;
cout << "Matrix A = " << endl;
cout << A << endl;
cout << endl;

// start at element A[0][1], in the upper triangle of the symmetric matrix A
int k=0;
int l=1;

double largest = max_offdiag_symmetric(A,k,l);

cout << "Largest (in absolute value) superdiagonal element of A is: A[k][l] = A[";
cout << k << "][" << l <<"] = " << largest << endl << endl;
/****/
return 0;
}//:~main()

