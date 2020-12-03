#include <stdio.h>

unsigned long long int fibonacci(unsigned int);

int main (void)
{
    unsigned int n;
    // prompt for user input
    printf("Enter the n: ");
    scanf("%u", &n);    
    // display the number
    printf("%llu", fibonacci(n));
 
}// end function main

unsigned long long int fibonacci(unsigned int n)
{
    unsigned long long int x0 = 0; // 1st term
    unsigned long long int x1 = 1; // 2nd term
    unsigned long long int x2; // next term

    // loop until nth term
    for (unsigned int i = 2; i <= n; i++)
    {
        x2 = x0 + x1;
        x0 = x1;
        x1 = x2;    
    }

    return x0;
} // end function fibonacci
