#include <stdio.h>

int main( void )
{
    // initialize variables
    int year;
    int month;
    int days;
    int leapYear;
    int dayPos;
    int dayNum;
    int space;

    // prompt user for year input
    do {
        printf("1994 ile 1999 arasi bir yil giriniz: ");
        scanf("%d", &year);
        if (year < 1994 || year > 1999) {
            printf("Yanlis girdi, lutfen 1994-1994 arasinda bir yil giriniz.\n");
        }
    } while (year < 1994 || year > 1999);
    // switch cases for starting positions of days
    switch (year) 
    {
    case 1994:
        dayPos = 6;
        break;

    case 1995:
        dayPos = 7;
        break;

    case 1996:
        dayPos = 1;
        break;

    case 1997:
        dayPos = 3;
        break;

    case 1998:
        dayPos = 4;
        break;

    case 1999:
        dayPos = 5;
        break;

    } // end while

    // checks if its a leap year or not
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        leapYear = 1;
    } 
    else {
        leapYear = 0;
    } // end if

    // display months
    for (month = 1; month <= 12; month++) {
        switch (month) 
        {
        case 1:
            printf( "\n%14s %d\n", "Ocak", year);
            days = 31;
            break;

        case 2:
            printf("\n\n%14s %d\n", "Subat", year);
            days = leapYear == 1 ? 29 : 28;
            break;

        case 3:
            printf("\n\n%14s %d\n", "Mart", year);
            days = 31;
            break;

        case 4:
            printf("\n\n%14s %d\n", "Nisan", year);
            days = 30;
            break;

        case 5:
            printf("\n\n%14s %d\n", "Mayis", year);
            days = 31;
            break;

        case 6:
            printf("\n\n%14s %d\n", "Haziran", year);
            days = 30;
            break;

        case 7:
            printf("\n\n%14s %d\n", "Temmuz", year);
            days = 31;
            break;

        case 8:
            printf("\n\n%14s %d\n", "Agustos", year);
            days = 31;
            break;

        case 9:
            printf("\n\n%14s %d\n", "Eylul", year);
            days = 30;
            break;

        case 10:
            printf("\n\n%14s %d\n", "Ekim", year);
            days = 31;
            break;

        case 11:
            printf("\n\n%14s %d\n", "Kasim", year);
            days = 30;
            break;

        case 12:
            printf("\n\n%14s %d\n", "Aralik", year);
            days = 31;
            break;
        } // end for

    // display weekdays
    printf("Pts Sal Car Per Cum Cmt Paz\n");
    
        for (space = 1; space < dayPos; space++) {
            printf("    ");
            } // end for
        for (dayNum = 1; dayNum <= days; dayNum++) {
            printf("%2d  ", dayNum);
            if (dayPos % 7 == 0) {
                printf("\n");
                dayPos = 1;
            }
            else {
                ++dayPos;
            } // end if
        } // end for 
    } // end for
} // end function main