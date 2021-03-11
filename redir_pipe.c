#include"headers.h"

int redpipe(char **command, char home_dir[], int process[]){
    
    int pipecount=0,redinput=0,redoutput=0,append=0;
    char *input=NULL, *output=NULL;
    int vwrite=1,i=0;

    while(command[i]!=NULL){

        if(strcmp(command[i], "<")==0){
            redinput=1;
            if(command[i+1]==NULL){
                perror("INVALID SYNTAX\n");
                exit(0);
            }
        }
        if(strcmp(command[i], "|")==0){
            pipecount++;
            if(command[i+1]==NULL){
                perror("INVALID SYNTAX\n");
                exit(0);
            }
        }
        if(strcmp(command[i], "|")==0){
            pipecount++;
            if(command[i+1]==NULL){
                perror("INVALID SYNTAX\n");
                exit(0);
            }
        }
        if(strcmp(command[i], ">>")==0 || strcmp(command[i], ">")==0){
            if(strcmp(command[i], ">")==0){
                append=1;
            }
            redoutput=1;
            if(command[i+1]==NULL){
                perror("INVALID SYNTAX\n");
                exit(0);
            }
            output=command[i+1]; break;
        }
        i++;
    }
    if(redinput==0 && pipecount==0 && redoutput==0){
        return run_command(command,home_dir,process);
    }
}
