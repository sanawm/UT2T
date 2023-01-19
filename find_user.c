void find_user(char* user_typed,user* head_of_list){
    user* current;
    current=head_of_list;
    int i=1;
    int j=0;
    int size=0;
    while(user_typed[i]!=' ')
        i++;
    i++;
    char* name_of_user=(char*)malloc((size+1)*sizeof(char));
    while(user_typed[i]!=' ') //separate the username
    {
        size++;
        name_of_user[j]=user_typed[i];
        name_of_user=(char*)realloc(name_of_user,((1+size)*sizeof(char)));
        j++;
        i++;
    }
    name_of_user[j]='\0';
}
    