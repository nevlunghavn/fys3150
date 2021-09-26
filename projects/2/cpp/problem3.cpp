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
  const int N = 6;
  int n = N + 1;
  double h = 1.0/(double)n;

  //const double h2 = 1.0E0/4.9E1;
  const double h2 = h*h;
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
  cout << "The relative error in the eigenvalues abs((analytic-Armadillo)/analytic):" << endl;
  cout << endl;
  for(int i = 0; i<6; i++){
    cout << scientific_format(std::abs((L[i]-eigval[i])/L[i])) << endl;
  }
  cout << endl;










  cout << endl;
  cout << "The corresponding eigenvectors using Armadillo are:" << endl;
  cout << endl;
  cout << eigvec << endl;
for(int i = 0; i<36; i++){
  cout<< eigvec[i] << endl;
}
  




  // for(int i=0;i<6;i++){
  //   for(int j=0;j<6;j++){
  //     cout << scientific_format (eigvec[i]);
  //   }
  // cout << endl;
  // }

std::vector<double> V = bb_eigenvec(6,2);
// for(double elem : V){
//   cout << scientific_format(elem) << endl;
// }
std::vector<double> V_normal = normalize_vec(V);
for(double elem : V_normal){
  cout << scientific_format(elem) << endl;
}

//create a 6x6 matrix B from the normalized analytical 
//eigenvectors of A

std::vector<std::vector<double>> B;
for(int i=1;i<7;i++){
  B.push_back(normalize_vec(bb_eigenvec(6,i)));
}


//print B

cout<<endl;
cout << "Eigenvectors relative error abs((analytic - Armadillo)/analytic):" << endl;
cout<<endl;
for(int i=0;i<6;i++){
  for(int j=0;j<6;j++){
    //cout << scientific_format (std::abs( (B[i][j] - eigvec[i][j])/B[i][j] ));
    cout << scientific_format (B[i][j]);
  }
  cout << endl;
}
cout<<endl;

cout<< B[0][0]<<endl;

cout<<endl;
cout<< "Eigenvalues relative error abs((analytic - Armadillo)/analytic): " << endl;
cout<<endl;
for(int i = 0;i<(int)eigval.size();i++){
  cout << scientific_format(std::abs((L[i]-eigval[i])/L[i])) << endl;
}











/************************************************/
  return 0;
}//:~main()
