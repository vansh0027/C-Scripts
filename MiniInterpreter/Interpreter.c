/* Name: Vansh Gupta
Project Type: Mini Interpreter in C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_VARIABLES 26
int letters[NUM_VARIABLES];


void setVariable(char variable, char value){
    letters[variable-'a']=value;
}
void addVariable(char firstVariable, char secondVariable){
    letters[secondVariable-'a']= letters[firstVariable-'a']+ letters[secondVariable-'a'];
}
void subtractVariable(char firstVariable, char secondVariable){
    letters[secondVariable-'a']= letters[secondVariable-'a']- letters[firstVariable-'a'];
}
void multiplyVariable(char firstVariable, char secondVariable){
    letters[firstVariable-'a']= letters[firstVariable-'a']* letters[secondVariable-'a'];
}
void divideVariable(char firstVariable, char secondVariable){
    letters[firstVariable-'a']= letters[firstVariable-'a']/letters[secondVariable-'a'];
}

int
main ()
{
char inputLine[100];
while(fgets(inputLine,sizeof(inputLine),stdin)!=NULL){
char command[20];
char firstVariable;char secondVariable;
int valueSet;
if(inputLine[0]=='#'){
    continue;
}

inputLine[strlen(inputLine)]=0;
if(sscanf(inputLine,"%s %c to %d", command,&firstVariable,&valueSet)==3){
    setVariable(firstVariable, valueSet);
}
else if(sscanf(inputLine,"%s %c to %c", command,&firstVariable,&secondVariable)==3||sscanf(inputLine,"%s %c from %c", command,&firstVariable,&secondVariable)==3||sscanf(inputLine,"%s %c by %c", command,&firstVariable,&secondVariable)==3){
    if(strncmp(command,"add",3)==0)
    {
        addVariable(firstVariable,secondVariable);
    }
   else if(strncmp(command,"subtract",8)==0)
    {
        subtractVariable(firstVariable,secondVariable);
    }
    else if(strncmp(command,"multiply",8)==0)
    {
        multiplyVariable(firstVariable,secondVariable);
    }
    else if(strncmp(command,"divide",6)==0)
    {
        divideVariable(firstVariable,secondVariable);
    }
}
else if(sscanf(inputLine,"%s %c", command, &firstVariable)==2){
    if(strncmp(command,"print",5)==0)
    {
        printf("%d\n",letters[firstVariable-'a']);
    }
}
}
return 0;
}
