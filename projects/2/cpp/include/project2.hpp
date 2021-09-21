#ifndef __project2_hpp__  
#define __project2_hpp__

// Now we include headers we need
#include <armadillo>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>



std::vector<double> bb_eigenval(int N, double a, double d);

std::vector<double> bb_eigenvec(int N, int i);

std::vector<double> normalize_vec( std::vector<double> v);

#endif  // end of include guard __project2_hpp__