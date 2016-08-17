#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int i;
    char fileName[30];
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    const size_t line_size = 300;
    line = malloc(line_size);
    if( access( "fileNames.lst", F_OK ) == -1 )
        system("crunch 3 3 abcdefghijklmnopqrstuvwxyz -o fileNames.lst");
    else printf("fileNames.lst already exists.\n");
    fp = fopen("./fileNames.lst","r");

while (fgets(line, line_size, fp) != NULL)  {
    printf("%s",line);
    system("read -r -p \"Press space to continue...\" key");
}
    return 0;
}
