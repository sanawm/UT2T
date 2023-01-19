char* command_recognition(*command){
    char login[6]="login";
    char signup[7]="signup";
    char post[5]="post";
    char like[5]="like";
    char logout[7]="logout";
    char delete[7]="delete";
    char info[5]="info";    
    char find_user[10]="find_user";
    
    if(strcmp(command,login)==0)
        return
      