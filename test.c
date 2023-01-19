#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"test.h"
typedef struct post post; 
struct post{
    int likes;
    char *post_description;
};
typedef struct user user; 
struct user{
    char name[10];
    char password[10];
    post all_post[10];
    int post_id;
    user *next;

};
void test(user *head_of_list){
    user* current=head_of_list;
    //printf("%s",head_of_list->name);
   // printf("%s",head_of_list->next->name);
   // printf("%s",head_of_list->next->next->name);

    
    while(current!=NULL){
        printf("%s,",current->name);
        current=current->next;

    }
}