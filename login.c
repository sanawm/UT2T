#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"login.h"
//we pass the head of account list and user typed to this function
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
user* login_user(char* user_typed,struct user* head_of_list){
        user* current=head_of_list;
        int i=1;
        int j=0;
        int size=0;
        while(user_typed[i]!=' ')
            i++;
        i++;
        char* name_of_user=(char*)malloc((size+1)*sizeof(char));
        while(user_typed[i]!=' ') //separates the username that user want to login its
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
        size=0;
        char* password_of_user=(char*)malloc((size+1)*sizeof(char));
        while(user_typed[i]!='\0') //separates the password that user want to login its
        {
            size++;
            password_of_user[j]=user_typed[i];
            password_of_user=(char*)realloc(password_of_user,((1+size)*sizeof(char)));
            j++;
            i++;
        }
        password_of_user[j]='\0';
        
        while(current!=NULL){  
            if(strcmp(current->name,name_of_user)==0){ //The desired username was found
                if(strcmp(current->password,password_of_user)==0){ //checking the password
                    printf("Hi %s, You have entered to your account!",current->name);
                    return current;
                }
                else
                    printf("your password in incorrect!");

            }
            else{
                current=current->next;

            }
        }
        printf("You do not have account, please signup!\n");
        
        free(name_of_user);
        free(password_of_user);
}
