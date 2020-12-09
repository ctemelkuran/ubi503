#include <stdio.h>
#define SIZE 1000

//The Sieve of Eratosthenes

void printNumbers(int array2[], int len);

int main()
{
    // initialize array and variables
    int array1[SIZE];
    size_t i;
    size_t j;

    // all elements initialized to 1
    for (i = 0; i < SIZE; i++) {
        array1[i] = 1;
    }

    for (i = 2; i < SIZE; i++) {
        if (array1[i] == 1)
            for (j = i + 1; j < SIZE; j++) {
            // check if the number is already not prime
                if (array1[j] == 0)
                    continue;
                // check if it's prime
                else if (j % i == 0) {
                    array1[j] = 0;
                } 
            }// end inner for
        }// end outer for
    
    // call for printNumbers function to display results
    printNumbers(array1, SIZE); 

} // end main

// function for displaying prime numbers
void printNumbers(int array2[], int len)
{
    size_t i;

    printf("Prime numbers up to %d:\n", SIZE);

    for (i = 2; i < len; i++) {
        if (array2[i] == 1)
            printf("%d ", i);
    }
}// end printNumbers