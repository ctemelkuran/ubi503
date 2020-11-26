#include <stdio.h>
#include <math.h>

int main(void)
{
    int code = 0;
    float weekSalary;
    float hours;
    float hourRate;
    float weekSale;
    float itemAmount;
    float itemFee;
    unsigned int count1 = 0;
    unsigned int count2 = 0;
    unsigned int count3 = 0;
    unsigned int count4 = 0;
    float salary1 = 0;
    float salary2 = 0;
    float salary3 = 0;
    float salary4 = 0;

    printf("Enter Employee Paycode(-1 to end): ");  

    scanf("%i",&code);
    
    // loop until 0 is typed
    while (code != -1 ) {
        
        // determine which code was input
        switch (code)
        {
        case 1:
            ++count1;
            printf("Enter weekly salary: ");
            scanf("%f", &weekSalary);
            salary1 += weekSalary;
            break;

        case 2:
            ++count2;
            printf("Working hour:");
            scanf("%f", &hours);
            printf("Hourly payment:");
            scanf("%f", &hourRate);
            if (hours <= 40) 
                salary2 += hours * hourRate;
            else
                salary2 += hourRate * (40 + (hours-40) * 1.5);            
            break;            

        case 3:
            ++count3;
            printf("Weekly sale amount: ");
            scanf("%f", &weekSale);
            salary3 += (250 + 0.057 * weekSale);
            break;  

        case 4:
            ++count4;
            printf("Amount of items: ");            
            scanf("%f", &itemAmount);
            printf("Fee per item: ");
            scanf("%f", &itemFee);  
            salary4 += itemAmount * itemFee;          
            break;

        default:
            printf("Incorrect code entered.\n");
            printf("Enter new paycode please.\n");
            break;
        } //end switch
        printf("%s", "\nEnter Employee Paycode(-1 to end): ");
        scanf("%i", &code);        
    } //end while

printf("\n%s%43s%11s\n","Role","Number of Employees","Salary");
printf("Managers: %28u%19.2f\n",count1, salary1);
printf("Hourly workers: %22u%19.2f\n",count2, salary2);
printf("Comission workers: %19u%19.2f\n",count3, salary3);
printf("Pieceworkers: %24u%19.2f\n\n",count4, salary4);

} // end fuction main