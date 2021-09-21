/**
 * FYS3150, project 1, problem 2
 * calculates u(x) for a set of points x and writes x, u(x) to file.
 * u(x) is an analytic solution of -u"(x) = 100 exp(-10x) 
 **/

#include <iostream> 
#include <fstream> // needed for file i/o
#include <math.h>  // needed for exponential function definition
#include <iomanip> // needed to use manipulators with parameters (precision, width)
using namespace std;

// save the current settings for precision
ios::fmtflags old_settings = cout.flags(); //save previous format flags
int old_precision = cout.precision(); // save previous precision setting

// function to generate and retrun mesh points along x.
double * getX();


// function to evaluate u(x) 
double u(double x){
    return 1.0 - (1.0 - exp(-10.0)) * x - exp(-10.0*x);
}

int main () {
    ofstream outFile("../data/x_u.dat");

    // set output format both for standard output and file output
    std::cout.precision(5);
    std::cout << std::scientific;
    outFile.precision(5);
    outFile << std::scientific;



    double *x;
    x = getX();
    outFile << "x           u(x)" << endl;
    outFile << "=======================" << endl;
    for ( int i = 0; i < 101; i++ ) {
        outFile <<  *(x + i) << " " << u(*(x+i)) <<endl;
    }

    // restore output format to default
    cout.flags(old_settings);
    cout.precision(old_precision);

    return 0;
}

double * getX() {
    double min_x = 0.0E0;          // lower limit of x
    double max_x = 1.0E0;          // upper limit of x
    static double  x[101];         // array to hold calculated x values (100 intervals = 101 boundary points)
    int n = 100;                   // number of intervals
    double h = (max_x - min_x)/n;  // size of intervals along x
    for(int i=0; i<n+1; i++){
        x[i] = i * h;
        }
    return x;  
}

/**
 * references:
 * 1. "Introduction to C++", https://anderkve.github.io/FYS3150/book/introduction_to_cpp/intro.html
**/