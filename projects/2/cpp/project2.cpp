#include "utils.hpp"

const double PI  =3.141592653589793238463;

/**
 * specialized functions
 * These are not of general use
 * 
 */
// function to return the analytical eigenvalues for the buckling beam equation
// from problem 3 of project 2

std::vector<double> bb_eigenval(int N, double a, double d){
    std::vector<double> L;
    for(int i=1; i<N+1; i++){
        L.push_back(d + 2.0*a*std::cos((double)i*PI/(6+1)));
        }
    return L;
}

// function to return one analytical eigenvector for the buckling beam equation
// from problem 3 of project 2
// 
std::vector<double> bb_eigenvec(int N, int i){
    std::vector<double> V;
    //double sum_of_squares = 0;
    for (int j = 1; j < N+1; j++){
        double component = std::sin(((double)j*double(i) * PI)/(N+1));
        V.push_back(component); 
    }
    return V;
}

// function to return a normaized copy of vector. 
// No elegant code, but it does the job
std::vector<double> normalize_vec(std::vector<double> v){
    double abs2 = 0;
    std::vector<double> normal;
    for (double elem : v){
        abs2 = abs2 + elem*elem;
    }
    double abs = std::sqrt(abs2);
    for (double elem : v){
        normal.push_back(elem/abs);
    }
    return normal;
}