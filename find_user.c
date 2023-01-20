#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"find_user.h"
#include"separate_username.h"
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
int find(char* user_typed,user* head_of_list){
    int flag=0;
    char heart=3;
    user* current;
    current=head_of_list;
    while(current!=NULL){
        if(strcmp(current->name,separate_username(user_typed))==0){
            printf("Name:%s\nPosts:\n",current->name);
            if(current->post_id==0){
                printf("This user does not have any posts\n");
                flag=1;    
                break;
            }
            else
                while(current->all_post[current->post_id-1].post_description!=NULL){
                    printf("Post number%d: %s   %c:%d\n",current->post_id,current->all_post[current->post_id-1].post_description,heart,current->all_post[current->post_id-1].likes);
                    (current->post_id)++;
                }
        }
        else
            current=current->next;
    }
    if(flag==1)
        return 0;
    else
        printf("There is no such username\n"); //if the username does not found
}


    