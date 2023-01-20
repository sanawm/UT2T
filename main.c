#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"scan_user_typed.h"
#include"separate_command.h"
#include"signup.h"
#include"login.h"
#include"post.h"
#include"info.h"
#include"like.h"
#include"find_user.h"
//#include"delete.h"
#include"separate_username.h"
#include"separate_password.h"
#include"separate_postid.h"
#include"save_user_info.h"

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
int main(){
    char login[6]="login";
    char signup[7]="signup";
    char post[5]="post";
    char like[5]="like";
    char logout[7]="logout";
    char delete[7]="delete";
    char info[5]="info";    
    char find_user[10]="find_user";
    int true=1; //for the main loop 
    int quit=1; //for the login loop
    char *user_typed;
    char* command;
    user* head_of_list=NULL;
    user* current;
    user* new_user;
    user* logined_user;
    while(true){
        printf("What do you want to do?\n");
        user_typed=scan_user_typed(); //resiving all of things that user typed
        command=separate_command(user_typed);  //recognize the command
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
        else if(strcmp(command,login)==0){
            quit=1;
            logined_user=login_user(user_typed,head_of_list); //Find the desired user
            if(logined_user==NULL){  //Strengthening
                printf("You do not have account, please signup! OR Your password is incorrect!\n");
                quit=0;
            }
            while(quit){
                printf("\nWhat do you want to do %s?\n",logined_user->name);
                user_typed=scan_user_typed();
                command=separate_command(user_typed);
                if(strcmp(command,logout)==0){
                    printf("You chose logout, bye bye %s!\n",logined_user->name);
                    quit=0;
                }
                else if(strcmp(command,post)==0){
                    post_user(logined_user);
                }
                else if(strcmp(command,info)==0){
                    info_user(logined_user);
                }
                else if(strcmp(command,like)==0){
                    like_post(user_typed,head_of_list);
                }
                //else if(strcmp(command,delete)==0)
                  //  delete_post(logined_user,user_typed);
                

                else//Strengthening
                    printf("I don't understand what you mean, please write again\n");
            }
        }
        else if(strcmp(command,find_user)==0)
            find(user_typed,head_of_list);

                
        else if((strcmp(command,like)==0)||(strcmp(command,logout)==0)||(strcmp(command,post)==0)||(strcmp(command,info)==0)) //Strengthening
            printf("Please login to your account first, if you don't have an account, sign up!\n");

        else//Strengthening
           printf("I don't understand what you mean, please write again\n");

        //save_user_info(head_of_list);  
        
        printf("-------------------------------------------------\n");
    }
}