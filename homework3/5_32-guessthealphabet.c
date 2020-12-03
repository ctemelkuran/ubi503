#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// initialize functions
void introduction();
char getUserGuess();
void guessTheLetter(int);
int compareLetters(char, char);


int main(void)
{
    int random;

    // display intro
    introduction();

    // choose a random letter
	srand(time(NULL));
	random = rand()%(26)+65; //26 is letters in English alphabet, 65 is ASCII for A

    printf("***Random letter is %c***\n", random); // Shows the random letter if needed
    // call the guessTheLetter function and pass it the random letter
    guessTheLetter(random);

    return 0;
} // end function main


void guessTheLetter(int random)
{
    char guess;
    int count = 0;
    int win = 0;

    // loop until user wins
    while (win == 0)
    {
        // call getUserGuess function and get a guess
        guess = getUserGuess();
            
        // turn guess into uppercase
        guess = toupper(guess);

        // call the compareLetter function and pass it the random and guess
        win = compareLetters(random, guess);

        count++; // increment count

        // check if the user has won or not
        if (win == 0) 
        {
            
            if (guess < random) {
                printf("%d. Way behind! Please try again.\n",count);
                                
            }
            else if (guess > random) {
                printf("%d. Way ahead! Please try again.\n",count);                
            }    
        } 

        else if (win == 1)
        {
            printf("%d. Great! Your guess is right!\n", count);
            
            if (count < 5)
                printf("Either you know the secret or you are lucky!\n\n");
            else if (count == 5)
                printf("I guess you know the secret!\n\n");
            else
                printf("You should be able to do better!\n\n");
            
        }
    } // end while
    
} // end function guessTheLetter 


void introduction()
{
    printf("\nI have selected a character between A and Z.\n");
    printf("Try to guess the character selected by me!\n");
    printf("What is your guess?\n");
    
} // end function introduction 

char getUserGuess()
{
    char guess;
    // prompt for user input
    printf("Enter your guess: ");
    scanf("%c", &guess);
    getchar(); // getchar() added because scanf also takes newline as input
    return guess;
} // end function getUserGuess

int compareLetters(char random, char guess)
{
    if (random == guess)
        return 1;
    else
        return 0;
} // end function compareLetters
