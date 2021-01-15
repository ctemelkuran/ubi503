#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data; // each Node contains an integer
    struct Node *nextPtr; // pointer to next node
};

typedef struct Node ListNode; // synonym for struct Node
typedef ListNode *ListNodePtr;

// prototypes
void insert( ListNodePtr *sPtr, int value );
ListNodePtr merge( ListNodePtr xPtr, ListNodePtr yPtr );
void printList( ListNodePtr currentPtr );

int main(void)
{
    ListNodePtr startPtr1 = NULL; // initially there are no nodes
    ListNodePtr startPtr2 = NULL;

    srand(time(NULL)); // seed random 
    
    puts("Instertion for 1st list:");
    for (int i = 0; i < 5; i++)
    {
        int random = rand() % 50;
        insert(&startPtr1, random);
        printList( startPtr1 );
    }
    puts("\nInstertion for 2nd list:");
    for (int i = 0; i < 10; i++)
    {
        int random = rand() % 100;
        insert(&startPtr2, random);
        printList( startPtr2 );
    }

    puts("\nFirst linked list:");
    printList( startPtr1 );
    puts("Second linked list:");
    printList( startPtr2 );
    puts("Merged linked list:");
    printList( merge( startPtr1, startPtr2 ) );
}

void insert( ListNodePtr *sPtr, int value )
{
    ListNodePtr newPtr; // pointer to new node  
    ListNodePtr previousPtr; // ptr to previous node
    ListNodePtr currentPtr; // ptr to current node

    // memory allocation
    newPtr = (ListNodePtr)malloc(sizeof(ListNode));

    if (newPtr != NULL)
    {
        newPtr->data = value; // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        previousPtr = NULL;
        currentPtr = *sPtr;

        // loop to find the correct location
        while (currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // insert new node at beginning of the list
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else  //insert new node between previousPtr and currentPtr
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf("%d not inserted. No memory available!\n", value);
    }   
} // end function insert

// function merge to combine two lists
ListNodePtr merge( ListNodePtr xPtr, ListNodePtr yPtr )
{
    ListNode merge; 
    ListNodePtr mergePtr = &merge;          
    ListNodePtr begin = mergePtr;                              
    
    // loop if xPtr and yPtr is not null
    while ( xPtr != NULL && yPtr != NULL)      
    {
        // place the data in order
        if ( xPtr->data < yPtr->data)
        {
            mergePtr->nextPtr = xPtr;
            xPtr = xPtr->nextPtr;
            mergePtr = mergePtr->nextPtr;

        } 
        else
        {
            mergePtr->nextPtr = yPtr;
            yPtr = yPtr->nextPtr;
            mergePtr = mergePtr->nextPtr;
        }
    } //end while
    
    if ( xPtr != NULL )                         
    {
        mergePtr->nextPtr = xPtr;
    }
    else if ( yPtr != NULL )                           
    {
        mergePtr->nextPtr = yPtr;
    }   
    return begin->nextPtr;                        
} //end of function merge

// print the list
void printList( ListNodePtr currentPtr )
{
    // while not the end of the list
    while ( currentPtr != NULL )
    {
        printf("%d -> ", currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
    puts("NULL");
    
} // end function printList