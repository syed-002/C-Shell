#include "headers.h"

int run_command(char **command, char home_dir[],int process[]){
    
    if(strcmp(command[0],"cd")==0){
        c_cd(command, home_dir);
    }
    else if(strcmp(command[0],"echo")==0){
        c_echo(command);
    }
    else if(strcmp(command[0],"pwd")==0){
        c_pwd();
    }
    else if(strcmp(command[0],"ls")==0){
        c_ls(command, home_dir);
    }
    else if(strcmp(command[0],"setenv")==0){
        seten(command);
    }
    else if(strcmp(command[0],"unsetenv")==0){
        unseten(command);
    }
    else if(strcmp(command[0],"overkill")==0){
        overkill(command,process);
    }
    
}