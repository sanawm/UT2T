#include<stdio.h>
#include<stdlib.h>
#include"signup.h"
//this function makes an account for new users
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
user* signup_user(){
    char* name;
    char* password;
    user *new_user=(user*)malloc(1*sizeof(user));
    printf("You chose signup:\n");
    printf("Enter your name:");
    name=scan_user_typed();
    new_user->name=name;
    printf("Enter your password:");
    password=scan_user_typed();
    new_user->password=password;
    printf("Congratulations, your account has been created\n");
    new_user->post_id=0;
    new_user->next=NULL;
    return new_user;
    free(new_user);
}