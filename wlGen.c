#include<stdio.h>
#include<unistd.h>
int main(){
    char fileName[30];
    if( access( "fileNames.lst", F_OK ) == -1 )
        system("crunch 3 3 abcdefghijklmnopqrstuvwxyz -o fileNames.lst");




    return 0;
}
