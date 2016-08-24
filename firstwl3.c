// if#n => if number n
#include<stdio.h>
#include<string.h>
int main(){
    int i,total_words;
    char charset[] = "abcd";
    int length = 3, charset_length=strlen(charset);
    int pos[10],flag[10];
    memset(pos,-1,sizeof(pos)); // fill pos with -1
    memset(pos,0,length*4); // fill pos with 0 till length
    memset(flag,-1,sizeof(flag)); // fill flag with -1
    total_words = charset_length*charset_length*charset_length + charset_length;

    for(i=0;i<total_words+5;i++){

        if( length>=3 && flag[length-3]!= -1 ){ // if#3
            flag[length-3] = 2;
            if(pos[length-3] == charset_length ){
                pos[length-3] = 0;
            }
            printf("%c",charset[pos[length-3]]);
        }

        if( length>=2 && flag[length-2]!= -1 ){ // if#2
            flag[length-2] = 2;
            if(pos[length-2] == charset_length ){
                pos[length-2] = 0;
                if(flag[length-3] ==2 ) pos[length-3]++;
                flag[length-3] = 1;
            }
            printf("%c",charset[pos[length-2]]);
        }

        if( length>=1 ){ // if#1 this if prints the units place(last character) of the word.
            printf("%c\n",charset[pos[length-1]++]);
            if(pos[length-1] == charset_length ){
                pos[length-1] = 0;
                if(pos[length-2] != -1 ){
                    if(flag[length-2] ==2 ) pos[length-2]++;
                    flag[length-2] = 1;
                }
            }
        }
    }
    return 0;
}

