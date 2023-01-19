#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"like.h"
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
int like_post(char* user_typed,user* head_of_list){
    user* current=head_of_list;
    int i=1;
    int j=0;
    int size=0;
    char c=3;
    while(user_typed[i]!=' ')
        i++;
    i++;
    char* name_of_user=(char*)malloc((size+1)*sizeof(char));
    while(user_typed[i]!=' ') //separates the username that user want to like its posts
    {
        size++;
        name_of_user[j]=user_typed[i];
        name_of_user=(char*)realloc(name_of_user,((1+size)*sizeof(char)));
        j++;
        i++;
    }
    name_of_user[j]='\0';
    i++;
    j=0;
    int a;
    a=user_typed[i];//separates the post_id that user want to like its
    a=a-49;
    while(current!=NULL){
        if(strcmp(current->name,name_of_user)==0){
            (current->all_post[a].likes)++;
            printf("You liked this post from %s:%s  %c\n",current->name,current->all_post[a].post_description,c);
            return 0;
        }
        else
            current=current->next;
    }
}