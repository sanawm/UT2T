#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"info.h"
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
int info_user(user* logined_user){
    char heart=3;
    printf("Name:%s\n",logined_user->name);
    printf("Password:%s\n",logined_user->password);
    printf("Posts:\n");
    logined_user->post_id=1;
    while(logined_user->all_post[logined_user->post_id-1].post_description!=NULL){
        printf("Post number%d: %s   %c:%d\n",logined_user->post_id,logined_user->all_post[logined_user->post_id-1].post_description,heart,logined_user->all_post[logined_user->post_id-1].likes);
        (logined_user->post_id)++;
    }
    return 0;
}