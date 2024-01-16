/*Problem Statement: LED Display for Time Digits
Problem Description:
You are tasked with implementing a C program that converts individual digits of a time input into LED display representations. The LED display is represented using ASCII characters, specifically '*' and '.'. The program should take a time input in the format HHMMSS and display the LED representation for each digit.

Requirements:
LED Display Function (displayDecimalDigitsToLED):

Implement a function named displayDecimalDigitsToLED that takes a decimal digit as input and returns an array representing the LED display for that digit.
Use '*' to represent an illuminated LED and '.' to represent an unlit LED.
The LED display for each digit should be stored in an array and returned.
Main Function Usage:

Develop a main function that takes a time input (HHMMSS) from the user.
Extract individual digits from the input and use the displayDecimalDigitsToLED function to get the LED representations for each digit.
Print the LED representations of all digits back to back for visualizing the time on an LED display.
Example:
c
Copy code
#include <stdio.h>
#include <stdlib.h>

// Function prototype
int *displayDecimalDigitsToLED(int digit);

int main() {
  char input_time[7];
  int digit1, digit2, digit3, digit4, digit5, digit6;
  int *arr1, *arr2, *arr3, *arr4, *arr5, *arr6;

  printf("Input time (HHMMSS): ");
  fgets(input_time, 7, stdin);
  sscanf(input_time, "%1d%1d%1d%1d%1d%1d", &digit1, &digit2, &digit3, &digit4, &digit5, &digit6);

  // Display LED representation for each digit
  arr1 = displayDecimalDigitsToLED(digit1);
  arr2 = displayDecimalDigitsToLED(digit2);
  arr3 = displayDecimalDigitsToLED(digit3);
  arr4 = displayDecimalDigitsToLED(digit4);
  arr5 = displayDecimalDigitsToLED(digit5);
  arr6 = displayDecimalDigitsToLED(digit6);

  // Print LED representation for each digit back to back
  for (int i = 3; i >= 0; i--) {
    printf("%c %c %c %c %c %c \n", *(arr1 + i), *(arr2 + i), *(arr3 + i), *(arr4 + i), *(arr5 + i), *(arr6 + i));
  }

  // Free allocated memory
  free(arr1);
  free(arr2);
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);

  return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

int *displayDecimalDigitsToLED (int digit)//make array's of binary for every digit and pass along the pointer
{   int *arr=malloc(4);
   int var = 0b1000;
  for (int i = 3; i >= 0; i--)
    {
      int flag = digit;
      if (flag & var)
	{
	arr[i] = 42;}
      else
	arr[i] = 46;

      var >>= 1;


    }
    return arr;

}

int main ()//Process the input, print every ith value of all arrays back to back
{
  char input_time[7];
  int hours; int minutes; int seconds;
  int digit1;int digit2;int digit3;int digit4;int digit5;int digit6;
  int *arr1; int *arr2;int *arr3;int *arr4;int *arr5;int *arr6;
  printf("Input: ");
  fgets (input_time, 7, stdin);
  sscanf (input_time, "%1d%1d%1d%1d%1d%1d", &digit1, &digit2, &digit3, &digit4, &digit5, &digit6);
      arr1=displayDecimalDigitsToLED (digit1);
      arr2=displayDecimalDigitsToLED (digit2);
      arr3=displayDecimalDigitsToLED (digit3);
      arr4=displayDecimalDigitsToLED (digit4);
      arr5=displayDecimalDigitsToLED (digit5);
      arr6=displayDecimalDigitsToLED (digit6);

      for (int i = 3; i>=0 ; i--)
    {
        printf("%c %c %c %c %c %c \n",*(arr1+i),*(arr2+i),*(arr3+i),*(arr4+i),*(arr5+i),*(arr6+i));
    }

}
