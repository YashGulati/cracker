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

    while (fgets(line, line_size, fNames) != NULL)  {
        line[strcspn(li‌​ne, "\n")] = '\0';
        printf("Making File: %s.lst\n",line);
        strcpy(command, "crunch 8 8 -t ");
        strcat(command, line);
        strcat(command, strcat(command," -o"));
        puts(command);
        fCurrent = fopen(line,"w");
        //system(command);
        fclose(fCurrent);
        //system("read -r -p \"Press space to continue...\" key");
}

    return 0;
}
