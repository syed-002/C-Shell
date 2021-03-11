#include"headers.h"

void c_cd(char ** command,char home_dir[]){
    char new_path[PATH_MAX]={'\0'};
    if(command[1]==NULL){
        command[1]="~";
    }
    path_change_reverse(home_dir,new_path, command[1]);
    int check=chdir(new_path);
    if(check==-1){
        printf("No directory found\n");
    }
}
void c_pwd(){
    char path[PATH_MAX]={'\0'};
    getcwd(path,sizeof(path));
    printf("%s\n",path);
}
void c_echo(char ** command){
    for(int i=1;command[i]!=NULL;i++){
        printf("%s ",command[i]);
    }
    printf("\n");
}

void seten(char ** command){
    int tot=0;
    while(command[tot]!=NULL){
        tot++;
    }
    if(tot==1 || tot>3){
        perror("setenv<var> <var> or setenv<var>\n");
    }
    if(command[2]==NULL){
        command[2]="";
    }
    setenv(command[1],command[2],1);

}
void unseten(char **command){
    int tot=0;
    while(command[tot]!=NULL){
        tot++;
    }
    if(tot!=2){
        perror("unsetenv<var>\n"); return;
    }
    unsetenv(command[1]);
}