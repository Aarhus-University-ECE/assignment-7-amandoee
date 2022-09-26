#include "taylor_sine.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool compare_float(double tal1, double tal2, int precision) {

    double precision_decimal = pow(10,-precision);

    if (fabs(tal1-tal2) < precision_decimal) {
        printf("%x", fabs(tal1-tal2));
        printf("%d", precision_decimal);
        return true;
    } else {
        return false;
    }

}

int factorial(int n) {

    int sum = 1;
    for (int i=n; i>0; i--) {
        sum*=i;
    }
    return sum;
}


//angiv n antal decimaler til præcision.
double taylor_sine(double x, int n)
{
    int i;
    double sum = -1;
    double previous_sum = x;
    bool check;

    for (i=1; compare_float(previous_sum,sum,n) == false; i++) {

        printf(" sin(x)=%x, %x", previous_sum, sum);

        sum = (-(pow(x,1+2*i)/factorial(1+2*i)));
        
        if (i%2 == 0) {
            sum=-sum;
        }

        previous_sum+=sum;
    }
    
    return sum;
}