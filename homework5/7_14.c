#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define END 70

// prototypes
void startIntro();
void moveTurtle(int * turtlePtr);
void moveHare(int * harePtr);
void printPosition(const int* const turtlePtr, const int* const harePtr);

int main()
{
    startIntro(); // call for intro function

    srand(time(NULL)); // seed random
    // initialize variables
    int hare = 1;
    int turtle = 1;
    int clock = 0;

    while(turtle != END && hare != END){
        
        // move each animal
        moveTurtle(&turtle);
        moveHare(&hare);

        // display position
        printPosition(&turtle, &hare);
        
        clock++; // clock ticks per second
    }
    puts("RACE FINISHED!");
    // check the winner
    if(turtle > hare) {
        printf("TORTOISE WINS !!! YAY !!!\n");         
    }
    else if(turtle < hare) {
        printf("Hare wins. Yuch\n");      
    }
    else {
        printf("Looks like a tie but TORTOISE WINS!\n");
    }
    puts("");
} // end main

void startIntro()
{
    printf("\n\tBANG!!!!!\n");
    printf("\tAND THEY'RE OFF !!!!!\n");
    printf("***************************************\n");
}

void moveTurtle(int * turtlePtr) {
    // generate random integer i
    int i;
    i = rand()%10 + 1;

    if (i >= 1 && i <= 5) {
        // Fast plod
        *turtlePtr += 3;
    }
    else if (i >= 6 && i <= 7) {
        //Slip
        *turtlePtr -= 6;
    }
    else {
        //Slow pod
        *turtlePtr += 1;
    }

    if(*turtlePtr < 1) {
        *turtlePtr = 1;
    }
    else if (*turtlePtr > END) {
        *turtlePtr = END;
    }
} // end moveTurtle

void moveHare(int * harePtr) {
    // generate random int i
    int i;
    i = rand()%10 + 1;

    if (i >= 1 && i <= 2) {
        // Sleep
        *harePtr = *harePtr;
    }
    else if (i >= 3 && i <= 4) {
        //Big hop
        *harePtr += 9;
    }
    else if (i == 5) {
        //Big slip
        *harePtr -= 12;
    }
    else if (i >= 6 && i <= 8) {
        //Small hop
        *harePtr += 1;
    }
    else {
        //Small slip
        *harePtr -= 2;
    }

    if(*harePtr < 1) {
        *harePtr = 1;
    }
    else if (*harePtr > END) {
        *harePtr = END;
    } 
}// end moveHare

void printPosition(const int* const turtlePtr, const int* const harePtr) {
    int i;
    Sleep(100); //sleep 0.1 sec to observe the race
    if(*turtlePtr == *harePtr) {
        for(i = 1; i < *turtlePtr; i++){
            printf("%s", " " );
        }
        printf("OUCH!!!");                
    }
    else if(*turtlePtr < *harePtr) {
        for(i = 1; i < *turtlePtr; i++ ){
            printf("%s", " " );
        }   
        printf("T");
        
        for(i = 1; i < (*harePtr - *turtlePtr); i++) {
            printf("%s", " " );
        }
        printf("H");
    }
    else {
        for(i = 1; i < *harePtr; i++) {
            printf("%s", " ");      
        }     
        printf("H");
        
        for( i = 0; i < (*turtlePtr - *harePtr); i++) {
            printf("%s", " " );     
        }
        printf("T");
    }   
    printf("\n");    
} // end printPosition