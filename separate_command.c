#include<stdio.h>
#include<stdlib.h>
#include"separate_command.h"
//this function separates the command...for example:login, like,... 
char* separate_command(char *user_typed){
    int i=0;
    int size=0;
    char* separate_command=(char*)malloc((size+1)*sizeof(char));
    while(user_typed[i]!=' ')  //Identification of the command received from the user until it reaches Space
    {
        size++;
        separate_command[i]=user_typed[i];
        separate_command=(char*)realloc(separate_command,((1+size)*sizeof(char)));
        i++;
    }
    separate_command[i]='\0';
    return separate_command;
    free(separate_command);
}