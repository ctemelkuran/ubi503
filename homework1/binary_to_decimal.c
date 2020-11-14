#include <stdio.h>

int main(void)
{
    // initialize variables
    int binary = 0;     // user input
    int decimal = 0;    // decimal value
    int remainder = 0;  // remainder value
    int base = 1;       // variable for base 2

    // get a binary number
    printf("Input a binary number(Only 0s and 1s): ");
    scanf("%d", &binary);
    // display the binary value
    printf("Binary value = %d\n", binary);
    
    // check the number of digits
    if (binary < 0 || binary >= 99999) {
      printf("Invalid input.(Please enter less than 6 digits.)\n");
      return 0;
    } // end if
      
    // while loop for conversion
    while (binary != 0)
    {
        remainder = binary %10;
        // check if the input is binary
        if (!(remainder == 1 || remainder == 0)) {
          printf("Invalid input.(Please enter only 0s and 1s.)\n");
          return 0;
        } // end if

        decimal = decimal + (base * remainder);
        base *= 2;
        binary /= 10;
    } // end while

    // display decimal value
    printf("Decimal equivalent = %d\n", decimal);
} // end fuction main