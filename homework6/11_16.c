#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 1000
#define ASCIIstart 97
#define ASCIIend 122

int main(void) {

    // initialize variables
    FILE *inpfPtr, *cfPtr;
    int c; 
    unsigned int sum;
    char file_name[MAX_LEN];

    // ask for file name to user
    printf("Enter a file name: ");
    scanf("%s", file_name);

    // check if file can be opened and a file to write is created
    if ((cfPtr = fopen("count.dat", "w")) == NULL 
    || (inpfPtr = fopen(file_name, "r")) == NULL) {
      puts("File could not be opened");
    }
    
    else {

    // open input file in read mode
    inpfPtr = fopen(file_name, "r");

    // write to output file
    fprintf(cfPtr, "Character");
    fprintf(cfPtr, "%8s", "Count\n");
    
    // check for lowercase english ASCII letters
    for (int i = ASCIIstart; i <= ASCIIend; i++)
    {
        // initiliaze sum for summation of each character
        sum = 0;
        // read file data with fgetc to control while loop
        c = fgetc(inpfPtr);

        while (c != EOF) { 
            // get characters and make them lowercase
            c = tolower(fgetc(inpfPtr));
            // count the characters if they match
            if (c == i)
            {
                sum++; 
            }
            
        }
        
        // write to the output file
        fprintf(cfPtr, "%-11c%u\n", i, sum);
        // rewind to the beginning in the text file
        rewind(inpfPtr);
    }
    // close files
    fclose(cfPtr);
    fclose(inpfPtr);
    }
} // end function main