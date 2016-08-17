#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int i;
    char fileName[30];
    FILE *fNames,*fCurrent;
    char *line = NULL,command[100];
    char letters3[3];
    size_t len = 0;
    //size_t read;
    const size_t line_size = 300;
    line = malloc(line_size);
    if( access( "fileNames.lst", F_OK ) == -1 )
        system("crunch 3 3 abcd -o fileNames.lst");
    else printf("fileNames.lst already exists.\n");
    fNames = fopen("./fileNames.lst","r");
    i=0;
    while (fgets(line, line_size, fNames) != NULL)  {
        strtok(line, "\n");
        printf("\t%d",++i);
        printf("Making File: %s.lst\n",line);
        strcpy(command, "crunch 8 8 -t ");
        strcat(command, line);
        strcpy(command, strcat(command," -o ./wordlists/"));
        //strcat(command, strcat(command,line));
        //strcat(command, strcat(command,".lst"));
        puts(command);
        memset(command, 0, 100);
        //system(command);
        //system("read -r -p \"Press space to continue...\" key");
}

    return 0;
}
