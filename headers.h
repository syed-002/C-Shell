#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include <sys/stat.h>
#include<pwd.h>
#include<dirent.h>
#include <ctype.h>
#include <grp.h>
#include<time.h>
#include<signal.h>




void prompt(char home_dir[]);
void path_change(char home_dir[], char path[], char full_path[]);
void path_change_reverse(char home_dir[], char full_path[], char path[]);
void c_cd(char ** command,char home_dir[]);
void c_pwd();
void c_echo(char ** command);
void lswrite(char *file, int l, int a);
void fullper(char file[],char filepassed[]);
void c_ls(char **command, char home_dir[]);
void seten(char **command);
void unseten(char **command);
void overkill(char ** command,int process[]);
int run_command(char **command, char home_dir[],int process[]);
int redpipe(char **command, char home_dir[], int process[]);
