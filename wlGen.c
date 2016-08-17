#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int i;
    char fileName[30];
    FILE *fNames,*fCurrent,command[100];
    char *line = NULL;
    size_t len = 0;
    //size_t read;
    const size_t line_size = 300;
    line = malloc(line_size);
    if( access( "fileNames.lst", F_OK ) == -1 )
        system("crunch 3 3 abcd -o fileNames.lst");
    else printf("fileNames.lst already exists.\n");
    fNames = fopen("./fileNames.lst","r");

    while (fgets(line, line_size, fNames) != NULL)  {
        printf("Making file %s",line);
        fCurrent = fopen(line,"w");
        strcpy(command,strcat(strcat("crunch 8 8 abcd -t ",line),"@@@@@"));
        system(command);
        fclose(fCurrent);
        //system("read -r -p \"Press space to continue...\" key");
}

    return 0;
}
