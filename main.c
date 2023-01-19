#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"scan_user_typed.h"
#include"separate_command.h"
#include"signup.h"
#include"login.h"
#include"test.h"
#include"post.h"
#include"info.h"
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

int main(){

    char login[6]="login";
    char signup[7]="signup";
    char post[5]="post";
    char like[5]="like";
    char logout[7]="logout";
    char delete[7]="delete";
    char info[5]="info";    
    char find_user[10]="find_user";
    int true=1;
    int quit=1;
    int test=0;
    char *user_typed;
    char* command;
    user* head_of_list=NULL;
    user* current;
    user* new_user;
    user* logined_user;
 
    while(true){
        printf("What do you want to do?\n");
        user_typed=scan_user_typed();
        command=separate_command(user_typed);//recognize the command
       
        if(strcmp(command,signup)==0){
                new_user=signup_user();
                if(head_of_list==NULL){//adding the first account
                    head_of_list=(user*)malloc(1*sizeof(user));
                    head_of_list=new_user;
                }
                else{//adding other account
                    current = head_of_list;
                    while(current->next!=NULL){
                        current=current->next;
                    }
                    current->next=(user*)malloc(1*sizeof(user));
                    current->next=new_user;
                }
        }
        else if(strcmp(command,like)==0){
            like_post(user_typed,head_of_list);
        }
        
        
        /*if(strcmp(command,find_user)==0){
            find_user(user_typed);
        }*/
        
       else if(strcmp(command,login)==0){
            logined_user=login_user(user_typed,head_of_list);
            quit=1;
            while(quit == 1){
                printf("\nWhat do you want to do %s?\n",logined_user->name);
                user_typed=scan_user_typed();
                command=separate_command(user_typed);
                if(strcmp(command,logout)==0){
                    printf("You chose logout, bye bye %s!\n",logined_user->name);
                    quit=0;
                }
                if(strcmp(command,post)==0){
                    post_user(logined_user);
                }
                if(strcmp(command,info)==0){
                    info_user(logined_user);
                }
            
            }
        }
        else //Strengthening
        {
           if(test!=0)
                printf("I don't understand what you mean, please write again\n");

        }    
test++;


}
}