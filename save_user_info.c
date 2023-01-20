#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"save_user_info.h"
typedef struct post post; 
struct post{
    int likes;
    char *post_description;
};
typedef struct user user; 
struct user{
    char name;
    char password;
    post all_post[10];
    int post_id;
    user *next;
};
void save_user_info(user* head_of_list){
    FILE *fp;
    //printf(" \n %s \n",head_of_list->name);
    fp = fopen("C:/Users/r565/Desktop/CA3-github/UT2T/file/DATABASE.txt", "w+");
    user* tempUser = head_of_list;
    while(tempUser!=NULL){
        fprintf(fp,tempUser->name);
        fprintf(fp," ");
        fprintf(fp,tempUser->password);
        fprintf(fp," ");
        fprintf(fp,tempUser->post_id);
        fprintf(fp,"\n");

        tempUser = tempUser->next;
    }
    fclose(fp);
}