
//
// Defintions for functions declared in utils.hpp
//

// By including utils.hpp, we also include all 
// the headers included in utils.hpp (<armadillo>, <sstream>, ...)
#include "utils.hpp"

int i,j;

// Return a string with a double in scientific notation
std::string scientific_format(const double d, const int width, const int prec)
{
  std::stringstream ss;
  ss << std::setw(width) << std::setprecision(prec) << std::scientific << d;
  return ss.str();
}


// Return a string with an armadillo vector in scientific notation
std::string scientific_format(const arma::vec& v, const int width, const int prec)
{
  std::stringstream ss;
  for(double elem : v)
  {
    ss << scientific_format(elem, width, prec);
  }
  return ss.str();
}

// Create tridiagonal matrix from vectors.
// - lower diagonal: vector a, lenght n-1
// - main diagonal:  vector d, lenght n
// - upper diagonal: vector e, lenght n-1
arma::mat create_tridiagonal(const arma::vec& a, const arma::vec& d, const arma::vec& e)
{
  int n = d.n_elem;
  // Start from identity matrix
  arma::mat A = arma::mat(n, n, arma::fill::eye);

  // Fill first row (row index 0)
  A(0,0) = d[0];
  A(0,1) = e[0];

  // Loop that fills rows 2 to n-1 (row indices 1 to n-2)
  for (i=1;i<n-1;i++){
    A(i,i-1) = a[i];
    A(i,i) = d[i+1];
    A(i,i+1) = e[i];
  }
  
  // Fill last row (row index n-1)
  A(n-1,n-2) = a[n-2];
  A(n-1,n-1) = d[n-1];
  return A;
}


// Create a tridiagonal matrix tridiag(a,d,e) of size n*n
// from scalar input a, d and e
arma::mat create_tridiagonal(int n, double a, double d, double e)
{
  arma::vec a_vec = arma::vec(n-1, arma::fill::ones) * a;
  arma::vec d_vec = arma::vec(n, arma::fill::ones) * d;
  arma::vec e_vec = arma::vec(n-1, arma::fill::ones) * e;

  // Call the vector version of this function and return the result
  return create_tridiagonal(a_vec, d_vec, e_vec);
}


// Create a symmetric tridiagonal matrix tridiag(a,d,a) of size n*n
// from scalar input a and d.
arma::mat create_symmetric_tridiagonal(int n, double a, double d)
{
  // Call create_tridiagonal and return the result
  return create_tridiagonal(n, a, d, a);
}

double max_offdiag_symmetric(const arma::mat& A, int& k, int &l){
    for(int i=0;i<(int)A.n_rows;i++){
        for (int j=i+1;j<(int)A.n_cols;j++){
            if(std::abs(A.at(i,j)) > std::abs(A.at(k,l))){
                k = i;
                l = j;
            }
        }
    }

    return A.at(k,l);
}


// // Create a tridiagonal matrix tridiag(a,d,e) of size n*n, 
// // from scalar input a, d, and e. That is, create a matrix where
// // - all n-1 elements on the subdiagonal have value a
// // - all n elements on the diagonal have value d
// // - all n-1 elements on the superdiagonal have value e
// arma::mat create_tridiagonal(int n, double a, double d, double e)
// {
//   // Start from identity matrix
//   arma::mat A = arma::mat(n, n, arma::fill::eye) * d;

//   // Fill the first row (row index 0), e.g.
//   //A(0,0) = d;
//   A(0,1) = e;

//   // Loop that fills rows 2 to n-1 (row indices 1 to n-2)
//   for (i=1;i<n-1;i++){
//     A(i,i-1) = a;
//     //A(i,i) = d;
//     A(i,i+1) = e;
//   }

//   // Fill last row (row index n-1)
//   A(n-1,n-2) = a;
//   //A(n-1,n-1) = d;


//   return A;
// }

// // Create a symmetric tridiagonal matrix tridiag(a,d,a) of size n*n
// // from scalar input a and d.
// arma::mat create_symmetric_tridiagonal(int n, double a, double d)
// {
//   // Call create_tridiagonal and return the result
//   return create_tridiagonal(n, a, d, a);
// }
