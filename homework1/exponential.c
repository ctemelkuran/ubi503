#include <stdio.h>

int main(void)
{
    // initialize variables
    int inp_n;
    int i = 1;
    int fac = 1;
    float e = 1;

    // ask for number of iterations
    printf("Enter number of iterations: ");
    scanf("%d",&inp_n);
     
    // loop for calculations
    while( i <= inp_n) {
        fac = fac * i;
        i++;
        e = e + ((float)1 / fac);
    } // end while

    // display result
    printf("e = %f", e);
} // end main
