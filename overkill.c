#include"headers.h"

void overkill(char ** command,int process[])
{
    for(int i=0;i<1002;i++){
        if(process[i]!=-1){
            kill(process[i],9);
            process[i]=-1;
        }
    }
}