#include"headers.h"

void path_change(char home_dir[], char path[], char full_path[]){
    int k=1;
    for(int i=0;i<strlen(home_dir);i++){
        if(home_dir[i]!=full_path[i]){
            k=0; break;
        }
    }
    if(k==1){
        int i=1;
        path[0]='~';
        for(int j=strlen(home_dir);j<strlen(full_path);j++){
            path[i]=full_path[j]; i++;
        }
        path[i]='\0';
    }
    else
    {
        strcpy(path,full_path);
    }
}
void path_change_reverse(char home_dir[], char full_path[], char path[]){
    strcpy(full_path, home_dir);
    if(path[0]=='~'){
        strcpy(full_path, path+1);
    }
    else
    {
        strcpy(full_path,path);
    }
}

void prompt(char home_dir[]){
    char path[PATH_MAX]={'\0'}, full_path[PATH_MAX]={'\0'};
    char user[NAME_MAX]={'\0'},host[HOST_NAME_MAX]={'\0'};
    int a=getlogin_r(user, sizeof(user));
    gethostname(host, sizeof(host));
    getcwd(full_path,sizeof(full_path));
    path_change(home_dir,path,full_path);
    if(a==0){
        printf("%s@%s:%s",user,host,path);
    }
    
}