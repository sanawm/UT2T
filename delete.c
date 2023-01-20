#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"delete.h"
#include"separate_postid.h"
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
void delete_post(user* logined_user,char* user_typed){
    user* current;
    current=logined_user;
    current->all_post[separate_postid(user_typed)-2].next2=current->all_post[separate_postid(user_typed)];
    printf("Your post was deleted!\n");
}