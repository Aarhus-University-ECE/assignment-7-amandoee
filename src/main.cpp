extern "C"{
    #include "../include/taylor_sine.h"
}
#include <assert.h>
#include <stdio.h>
#include <math.h>


// Add your test cases for Exercise 1b,c) here
int main(int argc, char **argv)
{
    

    //virker ikke. Hvorfor ikke?
    //printf("%.10f, %.10f",taylor_sine(1,12), sin(1));
    

    //Skriv en funktoin der tjekker for +-5%... BEdre til testcases end assert, da der er tale om en approksimering, og assert er NØJAGTIG.
    assert(taylor_sine(1,15) == sin(1));
    /*
    assert(taylor_sine(900,5) == sin(900));
    assert(taylor_sine(-5,5) == sin(-5));
    assert(taylor_sine(1,5) == sin(0));
    */

    

    return 0;
}