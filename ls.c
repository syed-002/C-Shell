#include"headers.h"


void lswrite(char *file, int l, int a){
    struct stat st={0};
    int dir_check=0;
    if(NULL==file){
        file=".";
    }
    stat(file,&st);
    if(S_ISDIR(st.st_mode))
        dir_check=1;
    if(dir_check==1){
        char new[PATH_MAX]={'\0'};
        DIR *d; struct dirent *dir;
        if(file[strlen(file)-1]!='/'){
            int len=strlen(file);
            char *dup=malloc(len+2);
            strcpy(dup, file);
            dup[len]='/', dup[len+1]='\0';
            file=dup;
        }
        strcpy(new, file);
        d=opendir(file);
        if(d>=0 && l==0){
            while((dir=readdir(d))!=NULL){
                if((dir->d_name[0]=='.' && a==1) || (dir->d_name[0]!='.')){
                    printf("%s\n", dir->d_name);
                }
            }
            closedir(d);
        }
        else if(d>=0 && l==1){
            while((dir=readdir(d))!=NULL){
                 if((dir->d_name[0]=='.' && a==1) || (dir->d_name[0]!='.')){
                     strcat(new,dir->d_name);
                     fullper(new,dir->d_name);
                     strcpy(new,file);
                 }
            }
        }
    }
    else if(l==0){
        printf("%s\n",file);
    }
    else{
        fullper(file, file);
    }
}

void fullper(char file[],char filepassed[]){
    struct stat st={0};
    stat(file, &st);
    struct passwd *pws;
    struct group *grp;
    char time[100]={'\0'};
    int mode;
    mode=st.st_mode;

    if(S_ISREG(mode))printf("-");
    else if(S_ISDIR(mode)) printf("d");
    else printf("l");

    if(mode & S_IRUSR) printf("r");
    else printf("-");
    if(mode & S_IWUSR) printf("w");
    else printf("-");
    if(mode & S_IXUSR) printf("x");
    else printf("-");
    if(mode & S_IRGRP) printf("r");
    else printf("-");
    if(mode & S_IWGRP) printf("w");
    else printf("-");
    if(mode & S_IXGRP) printf("x");
    else printf("-");
    if(mode & S_IROTH) printf("r");
    else printf("-");
    if(mode & S_IWOTH) printf("w");
    else printf("-");
    if(mode & S_IXOTH) printf("x");
    else printf("-");

    grp=getgrgid(st.st_gid);
    pws=getpwuid(st.st_uid);
    
    strftime(time, sizeof(time),"%b %d %H:%M",localtime(&st.st_mtime));
    printf("%d %s %s %d %s %s\n",(int)st.st_nlink,pws->pw_name,grp->gr_name,(int)st.st_size,time,filepassed);

}
void c_ls(char **command, char home_dir[]){
    int l=0, a=0, i=0,c;
    char new[20][PATH_MAX]={'\0'};
    int k=0;
    while(command[i]!=NULL){
        i++;
    }
    extern char *arg;
    extern int ind;
    int size=i;
    while((c=getopt(size,command,"la"))!=-1){
        switch(c){
            case 'a':
                a=1;
                break;
            case 'l':
                l=1;
                break;
            case '?':
                return;
        }
    }
    for(int i=0;i<size;i++){
        if(strcmp(command[i],"ls") && (command[i][0]!='-' || strlen(command[i])==1))
        {   
            k=1;
            char original_path[PATH_MAX]={'\0'};
            path_change_reverse(home_dir ,original_path,command[i]);
            struct stat st={0};
            int z=stat(original_path, &st);
            if(z<0) printf("No file or directory %s found", command[i]);
            else{
                printf("%s:\n",command[i]);
                lswrite(original_path,l,a);
            }
        }
    }
    if(k==0){
        lswrite(NULL,l,a);
    }
}