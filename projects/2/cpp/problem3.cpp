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
  const int N = 99;
  int n = N + 1;
  double h = 1.0/(double)n;

  const double h2 = h*h;
  const double a = -1/h2;
  const double d = 2/h2;
  //const double e = a;

  // define the matrix A
  mat A = create_symmetric_tridiagonal(N, a, d);

  // print A to standard output to ensure it is correctly 
  // generated
  cout << "The matix A = " << endl;
  cout << endl;
  cout << A << endl;
  cout << endl;

  // using the analytical expressions
  cout << endl;
  cout << "The analytical eigenvalues of A are: " << endl;
  cout << endl;
  std::vector<double> L = bb_eigenval(N,a,d);
  for(double elem : L){
    cout << scientific_format(elem) << endl;
  }

  // using Armadillo
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

  //compare the analyical and Armadillo computations of the eigevalues.
  cout << endl;
  cout << "The relative error in the eigenvalues abs((analytic-Armadillo)/analytic):" << endl;
  cout << endl;
  for(int i = 0; i<N; i++){
    cout << scientific_format(std::abs((L[i]-eigval[i])/L[i])) << endl;
  }
  cout << endl;

  //these are the normalized values computed using Armadillo.
  //we multiply each vector by a scalar factor (-1) to match the
  //sign of the analytical values
  cout << endl;
  cout << "The corresponding eigenvectors using Armadillo are:" << endl;
  cout << endl;
  cout << (-1.0)*eigvec << endl;

  cout<< endl;
  cout<< "The analytical eigenvectors are: " << endl << endl;
  for (int i=1;i<N+1;i++){
    std::vector<double> V = bb_eigenvec(N,i);
    std::vector<double> V_normal = normalize_vec(V);
      for(double elem : V_normal){
        cout << scientific_format(elem) << endl;
      }
  cout << endl;
  }
  //create a NxN matrix B from the normalized analytical 
  //eigenvectors of A
  
  std::vector<std::vector<double>> B;
  for(int i=1;i<7;i++){
    B.push_back(normalize_vec(bb_eigenvec(N,i)));
  }
  
  
  //print B
  
  cout<<endl;
  cout << "Eigenvectors relative error abs((analytic - Armadillo)/analytic):" << endl;
  cout<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << scientific_format (std::abs( (B[i][j] - eigvec[i][j])/B[i][j] ));
      cout << scientific_format (B[i][j]);
    }
    cout << endl;
  }
  cout<<endl;
  
  
  cout<<endl;
  cout<< "Eigenvalues relative error abs((analytic - Armadillo)/analytic): " << endl;
  cout<<endl;
  for(int i = 0;i<(int)eigval.size();i++){
    cout << scientific_format(std::abs((L[i]-eigval[i])/L[i])) << endl;
  }
  
/************************************************/
  return 0;
}//:~main()
