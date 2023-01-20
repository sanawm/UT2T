#include<stdlib.h>
#include"separate_postid.h"
int separate_postid(char* user_typed){
    int i=1;
    int j=0;
    int size=0;
    //int* post_id=(int*)malloc(1*sizeof(int));
    int a=0;
    while(user_typed[i]!=' ')
        i++;
    i++;
    while(user_typed[i]!=' ')
        i++;
    i++;
    a=user_typed[i];
    a=a-49;
        //password_of_user[j]='\0';
        return a;
}