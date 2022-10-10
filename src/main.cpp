extern "C"{
    #include "../include/taylor_sine.h"
}
#include <assert.h>
#include <stdio.h>
#include <math.h>


// Add your test cases for Exercise 1b,c) here
int main(int argc, char **argv)
{
    

    // Test cases for Exercise 1b). The printed output shows comparison of the two functions.
    for (int i = -31; i < 32; i++) {
        double x = i * 0.1;
        printf("\n\n");
        double y = taylor_sine(x,1);
        double z = sin(x);
        printf("\n");

        printf("x = %f, taylor_sine(x) = %f, sin(x) = %f", x, y, z);
        }
    

    //The intervals of input x for which the two functions are most similar, is when x is closer to 0:
    //This can be seen by running the for loop above.
    //An increased precision value will determine how many iterations the loop in the taylor_sine function will run. Furthermore, if x is ALSO further from 0, the taylor_sine function will need more iterations.



    return 0;
}