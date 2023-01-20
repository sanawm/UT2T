#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"separate_username.h"


char* separate_username(char* user_typed){
    int i=1;
    int j=0;
    int size=0;
    while(user_typed[i]!=' ')
        i++;
    i++;
    char* name_of_user=(char*)malloc((size+1)*sizeof(char));
    while(user_typed[i]!=' ') //separates the username that user want to like its posts
    {
        size++;
        name_of_user[j]=user_typed[i];
        name_of_user=(char*)realloc(name_of_user,((1+size)*sizeof(char)));
        j++;
        i++;
    }
    name_of_user[j]='\0';
    return name_of_user;
}
