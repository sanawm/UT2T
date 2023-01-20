#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"like.h"
#include"separate_username.h"
#include"separate_password.h"
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
int like_post(char* user_typed,user* head_of_list){
    user* current=head_of_list;
    char c=3; //heart ascii
    while(current!=NULL){
        if(strcmp(current->name,separate_username(user_typed))==0){
            (current->all_post[separate_postid(user_typed)].likes)++;
            printf("You liked this post from %s:%s  %c\n",current->name,current->all_post[separate_postid(user_typed)].post_description,c);
            return 0;
        }
        else
            current=current->next;
    }
}