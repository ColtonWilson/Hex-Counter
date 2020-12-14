/*  Midterm2
 * 
 * Filename:    source_q2.cpp
 * Purpose:     Hexadecimal Addition
 * Author:      Colton Wilson
 * Student ID:  106-65-4060
 * 
 * 
 * Created on November 24, 2020, 1:31 PM
*/
//Directives
#include<iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;
//Constants
const int MAX_NUMBERS = 10;

//Function prototypes
long long int convertHex(char a[], int size);
//PreCondition: a has been declared an array and size has been declared
//PostCondition:long decimal value returned
//Purpose: Covert a given Hex value into decimal

void convertdec(char a[], long long int total, int& size);
//PreCondition: a has been declared an array, size and total have been declared
//PostCondition:N/A
//Purpose: Convert a decimal value to Hex

void printHex(char a[], int size);
//PreCondition: a has been declared an array and size has been declared
//PostCondition: N/A
//Purpose: Display Hex values to screen.

void newline();
//PreCondition: N/A
//PostCondition: N/A
//Purpose: Clear pending input from user

//Call main function
int main(void)
{ 
    //Declare Variables and Arrays
    char number1[MAX_NUMBERS], number2[MAX_NUMBERS], totalHex[MAX_NUMBERS], answer, character1, character2;
     long long int sum1, sum2, total;
     int elements1, elements2, elements3, i, j;
   
   //Do-while loop to repeat program if user wants
  do{
      //For loops to clear arrays and make elements equal to zero
     for(int i = 0; i < MAX_NUMBERS; i++)
     {
         number1[i] = '\0';
     }
     
     for(int i = 0; i < MAX_NUMBERS; i++)
     {
         number2[i] = '\0';
     }
          for(int i = 0; i < MAX_NUMBERS; i++)
     {
         totalHex[i] = '\0';
     }
     
     //Prompt User for first Hex number
        i = 0;
       cout << "Enter the first hexadecimal number(Maximum 10 digits) Hex digits are {0-9, A-F}:  ";
       cin.get(character1);
       //While loop to input each element and convert to uppercase
       while(i < MAX_NUMBERS && character1 != '\n')
       {
           number1[i] = toupper(character1);
           cin.get(character1);
           i++;         
       }
       //Putback enter character so line can be cleared
       cin.putback(character1);
       //Count to keep track of inputted elements
       elements1 = i;
       //Call newline function
       newline();
       //Prompt User for second Hex number
       j = 0;
       cout << "Enter the second hexadecimal number(Maximum 10 digits) Hex digits are {0-9, A-F}:  ";
       cin.get(character2);
       //While loop to input each element and convert to uppercase
       while(j < MAX_NUMBERS && character2 != '\n')
       {
           number2[j] = toupper(character2);
           cin.get(character2);
           j++;          
       }
       //Putback enter character so line can be cleared
       cin.putback(character2);
       //Count to keep track of inputted elements
       elements2 = j;
       //call newline function
       newline();
    //Call convertHex function for each inputted number   
    sum1 = convertHex(number1, elements1);
    sum2 = convertHex(number2, elements2);
    
    //Add both numbers together
    total = sum1 + sum2;
    //If statement to make sure number is not bigger than largest Hex(FFFFFFFFFF)
    if(total > 1099511627775)
    {
        cout << "Addition Overflow" << endl;
        cout << endl;
    }
    //If not bigger call convertdec function
    else
    {
     convertdec(totalHex, total, elements3);
     cout << "The sum of ";
     //Print first Hex to screen
     printHex(number1, elements1);
     cout << " and ";
     //Print second Hex to screen
     printHex(number2, elements2);
     cout << " is: ";
     //Print total to screen
     printHex(totalHex, elements3);  
     cout << endl; 
            
    }
       //Prompt if user would like to do another calculation.
       cout << "Would you like to preform another calculation (Y/y): ";
       cin >> answer;
       
       //Call newline function
       newline();

    }while(answer == 'Y' || answer == 'y');


    
    //Exit Main function
    exit(EXIT_SUCCESS);
}
//Function Definition of convertHex
 long long int convertHex(char a[], int size)
{
     //Declarations with function as scope
    long long int sum = 0, number = 0;
    //For loop to work through each element of array
    for(int i = 0; i < size; i++)
    {
        //Switch statement to convert char to int
        switch(a[i])
        {
            case'0':
                number = 0;
                break;
            case '1':
                number = 1;
                break;
            case '2':
                number = 2;
                break;
            case '3':
                number = 3;
                break;
            case '4':
                number = 4;
                break;
            case '5':
                number = 5;
                break;
            case '6':
               number = 6;
                break;
            case '7':
                number = 7;
                break;
            case '8':
                number = 8;
                break;
            case '9':
               number = 9;
                break;
            case 'A':
                number = 10;
                break;
            case 'B':
                number = 11;
                break;
            case 'C':
                number = 12;
                break;
            case 'D':
              number = 13;
                break;
            case 'E':
               number = 14;
                break;
            case 'F':
               number = 15;
                break;
                     
        }
        //Equation to convert a 16 base number to base 10
        sum = sum + (number * pow(16, (size-i)-1));
    }
    return(sum);
}
 //Function Definition of convertdec
 void convertdec(char a[], long long int total, int& size)
 {
     //Declarations with function as scope
     long int remainder;
     int j;
     
     j = 0;
     //For statement to work through each element in array
     for(int i = (MAX_NUMBERS - 1); i >= 0; i--)
     {
         //Equations to convert from decimal to Hex
         remainder = total % 16;
         total = total / 16;
         
         //Switch statement to convert from int to char
        switch(remainder)
          {
            case 0:
                a[i]='0';
                break;
            case 1:
                a[i] = '1';
                break;
            case 2:
                a[i] = '2';
                break;
            case 3:
                a[i] = '3';
                break;
            case 4:
                a[i] = '4';
                break;
            case 5:
               a[i] = '5';
                break;
            case 6:
               a[i] = '6';
                break;
            case 7:
                a[i] = '7';
                break;
            case 8:
                a[i] = '8';
                break;
            case 9:
              a[i] = '9';
                break;
            case 10:
                a[i] = 'A';
                break;
            case 11:
                a[i] = 'B';
                break;
            case 12:
               a[i] = 'C';
                break;
            case 13:
              a[i] = 'D';
                break;
            case 14:
               a[i] = 'E';
                break;
            case 15:
               a[i] = 'F';
                break;
         }
                 
        j++;
     }
     size = j;
 }
 //Function Definition of printHex
 void printHex(char a[], int size)
 {
     //For loop to print out each element
     for(int i = 0; i < size; i++)
     {
         cout << a[i];
     }
 }
 //Function Definition of newline
 void newline()
 {
     //Declarations with function as scope
     char symbol;
     //Do while loop to grab excess elements not needed
     do
     {
         cin.get(symbol);
         
     }while(symbol != '\n');
 }

