#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"separate_password.h"
char* separate_password(char* user_typed){
    int i=1;
    int j=0;
    int size=0;
    char* password_of_user=(char*)malloc((size+1)*sizeof(char));
    while(user_typed[i]!=' ')
        i++;
    i++;
    while(user_typed[i]!=' ')
        i++;
    i++;
        while(user_typed[i]!=' '){
            size++;
            password_of_user[j]=user_typed[i];
            password_of_user=(char*)realloc(password_of_user,((1+size)*sizeof(char)));
            j++;
            i++;
        }
        password_of_user[j]='\0';
        return password_of_user;
}