#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int HolyRomanEmpire(int changeThisNumber);
int Germania(char c);

int main()
{
    //declaration of keys and key test
    char keyTest[5]={0};
    printf("Please enter the Password\n");
    scanf("%s",keyTest);
    if (strcasecmp(keyTest,"IDF")!=0)
    {
        printf("Wrong key!");
        return 0;
    }

    system ("cls");
    //variables to store user input
    int userinput;
    //allows the user to either print out a specific number, or an entire table
    int userChoice;
    int i = 0;
    printf("Would you like to print 1)All numbers between 1 and 100. 2)Print a specific number. 3)Convert Roman Numeral to Decimal.\n");
    scanf("%i",&userChoice);
    //ensures the user only chooses 1,2, or 3
    if(!userChoice)
    {
        printf("Invalid Choice?\n");
        return 0;
    }
    system ("cls");
    //breaks up what the user wants to do in accordance with userChoice
    switch (userChoice)
    {   
        //if the user wants to print an entire table
        case 1:
        for(int i=1;i<=100;i++)
        {
            printf("%i is\t",i);
            HolyRomanEmpire(i);
        }
        break;
        
        //if the user wants to print a specific number
        case 2:
        //will prompt user for input
        printf("Please input the number you'd like converted to Roman Numbers(must be between 1-100)\n");
        scanf("%i",&userinput);
        //error handling
        if(!userinput)
        {
            printf("NULL\n");
            return 0;
        }
        else if (userinput>100|| userinput<0)
        {
            printf("Number not in specified range\n");
            return 0;
        }
        printf("%i is\t",userinput);
        HolyRomanEmpire(userinput);
        //end case 2
        break;

        //converts the roman numeral to decimal
        case 3:
        printf("");
        char roman_Number[1000];
        i=0;
        long int number =0;
        printf("Enter any roman number (Valid digits are I, V, X, L, C):  \n");
        scanf("%s",roman_Number);

        while(roman_Number[i])
            {
                //will only allow input if it is I,V, X, L, C,
                if(Germania(roman_Number[i]) < 0)
                {
                    printf("Invalid roman number : %c",roman_Number[i]);
                    return 0;
                }
                //will handle the error if it is input incorrectly
                if((strlen(roman_Number) -i) > 2)
                {
                    if(Germania(roman_Number[i]) < Germania(roman_Number[i+2]))
                    {
                        printf("Invalid roman number");
                        return 0;
                    }
                } //end error checking
                //will take the values, pass it into the function and add the values together
                if(Germania(roman_Number[i]) >= Germania(roman_Number[i+1]))
                {
                    number = number + Germania(roman_Number[i]);
                }
                else
                {
                    number = number + (Germania(roman_Number[i+1]) - Germania(roman_Number[i]));
                    i++;
                }
                i++;
            }
            //prints the decimal value
            printf("Its decimal value is : %ld",number);
            return 0;
            break;

        default:
        printf("Invalid choice!");
        break;
        
    }//end switch
}


//this function will convert what ever number is passed into a Roman numeral
int HolyRomanEmpire(int changeThisNumber)
{
    //variables to check which numbers will be in the roman numerals
    int divisible_by_50 = 50;   int divisible_by_10 = 10;
    int divisible_by_5 = 5;     int divisible_by_1 = 1;


    //where the magic happens
    if (changeThisNumber==100)
    {
        printf("C ",changeThisNumber);
        changeThisNumber-=100;
    }
    //handles if the number is 90-99
    if((changeThisNumber/10)==9)
    {
        printf("XC");
        changeThisNumber-=90;
    }
    //can only have one L, so this is an if statement
    if((changeThisNumber-50)>=0)
    {
        printf("L");
        changeThisNumber-=50;
    }
    //handle if the number is 40-49
    if ((changeThisNumber/10)==4)
    {
        printf("XL");
        changeThisNumber-=40;
    }
    //will populate the correct amount of 10's needed in the number
    while((changeThisNumber-10)>=0)
    {
        printf("X");
        changeThisNumber-=10;
    }
    //handles if the value in the 1's spot of the number is 9
    if (changeThisNumber==9)
    {
        printf("IX");
        changeThisNumber-=9;
    }
    //will print a V if the number in the 1's spot is 5,6,7,8 (already handled 9)
    if ((changeThisNumber-5)>=0)
    {
        printf("V");
        changeThisNumber-=5;
    }
    //handles if the number left over is 4
    if (changeThisNumber==4)
    {
        printf("IV");
        changeThisNumber-=4;
    }
    while(changeThisNumber!=0)
    {
        printf("I");
        changeThisNumber-=1;
    }
    printf("\n");
}
int Germania(char c)
{
    int value=0;
    //this baby is where we get values for the math in case 3
    switch(c)
    {
        case 'I':
        value = 1;
        break;
        case 'V':
        value = 5;
        break;
        case 'X':
        value = 10;
        break;
        case 'L':
        value = 50;
        break;
        case 'C':
        value = 100;
        break;
        case '\0':
        value = 0;
        break;
        default:
        value = -1;
        break;
    }
    return value;
}
