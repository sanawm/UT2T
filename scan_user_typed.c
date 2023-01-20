#include<stdio.h>
#include<stdlib.h>
#include"scan_user_typed.h"
//this function gets the all things that user typed...forexample:login user password
char* scan_user_typed(){
    char* user_typed=(char*)malloc(1*sizeof(char));
    int size=0;
    int counter=0;
    char c='\0';
    while(c!='\n') //Receive user_typed until got to enter
    {
        size++;
        c=getchar();
        user_typed[counter]=c;
        user_typed=(char*)realloc(user_typed,((1+size)*sizeof(char)));
        counter++;
    }
    user_typed[counter-1]='\0';
    return user_typed;
    free(user_typed);
}