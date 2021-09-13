/**
 * FYS3150, project 1, problem 7
 * This code is meant to be an implementation of the Thomas algorithm as 
 * described in the lectures. Unfortunately it does not produce the 
 * expected results.
 **/

#include <iostream> 
#include <fstream> // needed for file i/o
#include <math.h>  // needed for exponential function definition
#include <iomanip> // needed to use manipulators with parameters (precision, width)
using namespace std;

// save the current settings for precision
ios::fmtflags old_settings = cout.flags(); //save previous format flags
int old_precision = cout.precision(); // save previous precision setting

// function to return the RHS
double f(double x){
    return 100 * exp(-10*x);
}

int main () {
    ofstream outFile("../data/poisson.dat");

    // set output format both for standard output and file output
    std::cout.precision(5);
    std::cout << std::scientific;
    outFile.precision(5);
    outFile << std::scientific;

// start with n=10 steps => n+1 points => n-1 unknowns
static int n = 10;
// range of x
static double xmin = 0.0;
static double xmax = 1.0;
//step size
double h = (xmax-xmin)/n;
//x array 
//we are using a basic array which means we can not use variable n as size here
static double x[11];
for(int i=0; i<n+1; i++){
    x[i] = i*h;
}

//define all the arrays
// bt is btilde and gt is gtilde
double a[11];
for(int i=1;i<n+1;i++){
    a[i] = -1;
}
double b[11];
for(int i=0;i<n+1;i++){
    b[i] = -2;
}
double c[11];
for(int i=0;i<n;i++){
    c[i] = -1;
}
double bt[11];
bt[0] = b[0];
for(int i=1;i<n+1;i++){
    bt[i] = b[i] - (a[i]/bt[i-1])*c[i-1];
}
// first and last element of v is given by the Dirichlet conditions 
// the inner elements have to be calculated
double v[11];
v[0] = 0;
v[n+1] = 0;

// first and last elements of g are known
double g[11];
g[1] = h*h*f(x[1]) + v[0];
g[n] = h*h*f(x[n]) + v[n+1];
for(int i=1;i<n+1;i++){
    g[i] = h*h*f(x[i]);
}

double gt[11];
gt[1] = g[1];
for(int i=1;i<n+1;i++){
    gt[i] = g[i] - (a[i]/bt[i])*gt[i-1]; 
}

//back substitution
v[n] = gt[n]/bt[n];
for(int i=10;i>=1;i-=1){
    v[i] = (gt[i] - c[i]*v[i+1])/bt[i];
}


    int count = 1;
    for ( int i = 0; i < n+1; i++ ) {
        cout << count << "   [" << i << "]" << v[i] << endl;
        count++;
        
    }


    // restore output format to default
    cout.flags(old_settings);
    cout.precision(old_precision);

    return 0;
}


