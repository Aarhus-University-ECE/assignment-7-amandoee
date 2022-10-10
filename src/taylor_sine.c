#include "taylor_sine.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

//Function to compare the similarity of two double values. Determines whether or not the two values are equal up to a certain degree of precision (n decimal points).
int compare_float(double tal1, double tal2, int precision) {

    double precision_decimal = pow(10,-precision);

    if (fabs(tal1-tal2) < precision_decimal) {
        return 1;
    } else {
        return 0;
    }

}

//Function to calculate the factorial of a given number.
double factorial(int n) {

   double res = 1;
   for (int i = 1; i<n+1;i++) {
    res *= i;
   }

    return res;
}


//Function for approximating the sine of a given angle using the Taylor series. The loop stops when the difference between the current and previous approximation is less than a certain degree of precision (n decimal points).
double taylor_sine(double x, int n)
{
    int i;
    double xn = -1;
    double previous_sum = x;
    double pre_previous_sum = 0;
    int check = 0;

    for (i=1; check==0; i++) {
        xn = (-(pow(x,1+2*i)/factorial(1+2*i)));
        if (i%2 == 0) {
            xn=-xn;
        }

        pre_previous_sum = previous_sum;
        previous_sum += xn;

        if (compare_float(previous_sum,pre_previous_sum,n)==1) {
            check = 1;
        } 
    }
    
    return previous_sum;
}