#include<stdio.h>
#include<unistd.h>
int main(){
    char fileName[30];
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    if( access( "fileNames.lst", F_OK ) == -1 )
        system("crunch 3 3 abcdefghijklmnopqrstuvwxyz -o fileNames.lst");
    else printf("fileNames.lst already exists.\n");
    fp = fopen("fileNames.lst",'r');
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
        getch();
    }
    return 0;
}
