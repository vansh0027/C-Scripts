/* Problem Statement: String to Integer Conversion with Base Support
Problem Description:
Write a C program that provides a function to convert a given string representation of a number to an integer, considering different bases such as decimal, octal, and hexadecimal. The program should include a main function demonstrating the usage of the conversion function with different input strings.

Requirements:
Implement the strtoint function, which takes a string as input and returns the corresponding integer value.
The function should support converting numbers in decimal, octal (indicated by _08 in the string), and hexadecimal (indicated by _16 in the string) bases.
The main function should showcase the usage of strtoint by providing different input strings and printing the results.
Example:
c
Copy code
#include <stdio.h>

int main() {
  char *input1 = "2a_16";
  char *input2 = "42_10";
  char *input3 = "42";
  char *input4 = "52_08";
  
  int result1 = strtoint(input1);
  int result2 = strtoint(input2);
  int result3 = strtoint(input3);
  int result4 = strtoint(input4);
  
  printf("Result: %d\n", result1);
  printf("Result: %d\n", result2);
  printf("Result: %d\n", result3);
  printf("Result: %d\n", result4);
  
  return 0;
}
Note:
Ensure that the strtoint function correctly handles different base representations and produces the expected results.
  */
#include <unistd.h>
#include "myio.h"
#include "print.c"

#include <stdio.h>

static char buf[NBUF];
static int idx;
int power(int a, int b){
    if(b==0)
        return 1;
    else
        return a*power(a,b-1);
   }
int strtoint(char *str) {
    int base=10;
    int num=0;
    char *p;
    for( p=str;*p!='\0';++p){
        if (*p=='_')
            if(*(p+1)=='0'&&*(p+2)=='8')
            base=8;
            else if(*(p+1)=='1' && *(p+2)=='6'){
                base=16;
            }
        }// we have the base value
        int arr[NBUF];
        int idx=0;
    for( p=str;*p!='\0';++p){
        if(*p!='_'){
            if(*p>='0'&&*p<='9'){
            arr[idx]=(*p-'0');}
            else if(*p=='a'||*p=='A')
            arr[idx]=10;
            else if(*p=='b'||*p=='B')
            arr[idx]=11;
            else if(*p=='c'||*p=='C')
            arr[idx]=12;
            else if(*p=='d'||*p=='D')
            arr[idx]=13;
            else if(*p=='e'||*p=='E')
           arr[idx]=14;
            else if(*p=='f'||*p=='F')
            arr[idx]=15;
            idx++;
        }
        else{
            break;
        }}
        int idx2=idx;
        for(int i=0;i<idx;i++){
            num=num + arr[i] * power(base,idx2-1);
            idx2--;
        }
    return num;
}

int main ()
{
  char *input1 = "2a_16";
  char *input2= "42_10";
  char *input3= "42";
  char *input4= "52_08";
  int result1 = strtoint(input1);
  int result2 = strtoint(input2);
  int result3 = strtoint(input3);
  int result4 = strtoint(input4);
  print("Result: %d\n", result1);
  print("Result: %d\n", result2);
  print("Result: %d\n", result3);
  print("Result: %d\n", result4);
  return 0;
}

