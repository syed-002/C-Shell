#include"headers.h"

int N=1001;
char home_dir[PATH_MAX]={'\0'};

int main(){

    getcwd(home_dir, sizeof(home_dir));
    int process[N];
    for(int i=0;i<N;i++){
        process[i]=-1;
    }

    while(1){
        char input_token[20][MAX_INPUT]={'\0'};
        int wstatus;
        int status=waitpid(-1, &wstatus, WNOHANG);
        int ind=0;
        prompt(home_dir);
        
        for(int i=0;i<N;i++){
            if(kill(process[i],0)==-1){
                printf("process with %d ended successfully\n", process[i]);
                process[i]=-1;
            }
        }
        char input[MAX_INPUT]={'\0'}, new_input[MAX_INPUT]={'\0'};
        fgets(input,MAX_INPUT,stdin);
        input[strlen(input)-1]='\0';
        strcpy(new_input,input);
        char *tok =strtok(new_input,";");
        int i=0;
        while(tok!=NULL){
            strcpy(input_token[i],tok);
            tok=strtok(NULL,";");
            i++;
        }
        tok=NULL;
        char base[MAX_INPUT]={'\0'};
        for(int j=0;j<i;j++){
            strcpy(base,input_token[j]);
            int k=0;
            char **command=(char **)malloc(2048);
            tok=strtok(base," \t");
            while(tok!=NULL){
                command[k]=tok;
                tok=strtok(NULL, " \t");
                k++;
            }
            command[k]=NULL;
            ind=redpipe(command,home_dir,process);
            if(ind==1) break;

        }
        if(ind==1) break;
    }
}