#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"post.h"
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
void post_user(user* logined_user){
    int size=0;
    int counter=0;
    char c='\0';
    printf("You chose post\n");
    printf("please write your post:");
    char* post_text=(char*)malloc(1*sizeof(char));
    while(c!='\n')
    {
        size++;
        c=getchar();
        post_text[counter]=c;
        post_text=(char*)realloc(post_text,((1+size)*sizeof(char)));
        counter++;
    }
    post_text[counter-1]='\0';
    (logined_user->post_id)++;
    logined_user->all_post[(logined_user->post_id)-1].post_description=post_text;
    logined_user->all_post[(logined_user->post_id)-1].likes=0; 
    printf("Your post has been successfully registered\npost:%s, post_id:%d",logined_user->all_post[(logined_user->post_id)-1].post_description,logined_user->post_id);
}