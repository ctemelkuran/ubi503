#include <stdio.h>
 
int gcd(int x, int y);

int main()
{
    // initialize variables
    int x, y;

    // prompt for user input x and y
    printf("Enter integer x: ");
    scanf("%d", &x);

    printf("Enter integer y: ");
    scanf("%d", &y);
    printf("_______________________\n");
    // call the gcd function and display result
    printf("GCD is %d for %d and %d.", gcd(x, y), x,y);

} // end function main 
// recursive function to return gcd of x and y
int gcd(int x, int y)
{
    // if one of the integers is 0 
    if (x == 0) {
       return y;
    }
    if (y == 0) {
       return x;
    }
    // base case
    if (x == y)
        return x;
 
    //if x is greater
    if (x > y) {
        return gcd(x-y, y); // recursive case
    } 
    return gcd(x, y-x); // recursive case

} // end function gcd