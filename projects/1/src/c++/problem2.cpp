#include <iostream> 
#include <fstream> // needed for file i/o
#include <math.h>  // needed for exponential function definition
#include <iomanip> // needed to use manipulators with parameters (precision, width)
using namespace std;

// save the current settings for precision
ios::fmtflags old_settings = cout.flags(); //save previous format flags
int old_precision = cout.precision(); // save previous precision setting

// function to generate and retrun mesh points along x.
double * getX() {
    const int n = 100;             // number of intervals along x
    double min_x = 0.0E0;          // lower limit of x
    double max_x = 1.0E0;          // upper limit of x
    static double  x[101];         // array to hold calculated x values (n+1)
    double h = (max_x - min_x)/n;  // size of intervals along x
    for(int i=0; i<n+1; i++){
        x[i] = i * h;
        }
    return x;  
}

// function to evaluate u(x) 
double u(double x){
    return 1.0 - (1.0 - exp(-10.0)) * x - exp(-10.0*x);
}

int main () {
    ofstream outFile("x_u.dat");

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

/**
 * references:
 * 1. "Introduction to C++", https://anderkve.github.io/FYS3150/book/introduction_to_cpp/intro.html
 * 2. "Formatting Numbers with C++ Output Streams", David Kieras, EECS Dept., Univ. of Michigan
 * 3. scientific notation: https://www.cplusplus.com/reference/ios/scientific/
**/