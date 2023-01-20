#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"login.h"
#include"separate_username.h"
#include"separate_password.h"
//we pass the head of account list and user typed to this function to find the desired account:)
typedef struct post post; 
struct post{
    int likes;
    char *post_description;

};
typedef struct user user; 
struct user{
    char* name;
    char* password;
    post all_post[10];
    int post_id;
    user *next;
};
user* login_user(char* user_typed,struct user* head_of_list){
    user* current=head_of_list;
    int flag=0;
    char* password_of_user=separate_password(user_typed);
    while(current!=NULL){  
        if(strcmp(current->name,separate_username(user_typed))==0){ //The desired username was found
            if(strcmp(current->password,password_of_user)==0){ //checking the password
                printf("Hi %s, You have entered to your account!",current->name);
                return current;
            }
            else
                break;
        }
        else
            current=current->next;
    }
    current=NULL;
    return current;
}
