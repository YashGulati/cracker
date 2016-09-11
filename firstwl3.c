#include<stdio.h>
#include<string.h>
#include<math.h>
char charset[] = "abcd";
int length = 3 ;
int max_length;
int min_length;
int wc=0;
int wordCount(charlen,wordlen){
    if(wordlen == 1) return strlen(charset);
    return pow(strlen(charset),wordlen) + wordCount(charlen,wordlen-1);
}
int main(int args, char* argv[]){
    int i,total_words, dbg=0, count_only=1;
    int pos[10],flag[10];
    int charset_length = strlen(charset);
    void printer(){
        int p;
        for(p=length;p>=2;p--)
            if(flag[length-p]!= -1) printf("%c",charset[pos[length-p]]);
        printf("%c\n",charset[pos[length-1]++]);
    }
    void ifer(){
        int i;
     if( length>=1 ){ // if#1
            if(pos[length-1] == charset_length ){
                pos[length-1] = 0;
                if(pos[length-2] != -1 ){
                    if(flag[length-2] ==2 ) pos[length-2]++;
                    flag[length-2] = 1;
                }
            }
         }
        for(i=2;i<=length;i++){
        if( length>=i && flag[length-i]!= -1 ){ // if#i
            flag[length-i] = 2;
            if(pos[length-i] == charset_length ){
                pos[length-i] = 0;
                if(pos[length-(i+1)] != -1 ){
                    if(flag[length-(i+1)] ==2 ) pos[length-(i+1)]++;
                    flag[length-(i+1)] = 1;
                }
            }
        }
    }
    } if(dbg){
    printf("You typed the command: ");
    for(i=0;i<args;i++)
        printf("%s ",argv[i]);
    }
    memset(pos,-1,sizeof(pos));
    memset(pos,0,length*4);
    memset(flag,-1,sizeof(flag));
    total_words = wordCount(charset_length,length);
    if(count_only) { printf("\nNo. of Words will be: %d\nDo you want to continue (Y/N) default is N : ",total_words); count_only=getche(); printf("\n");
    if(count_only==(int)'N' || count_only==(int)'n' || count_only==13) return 0;  }
    for(i=0;i<total_words;i++){
        if(dbg==1) printf("%d: ",i);
        ifer();
        printer();
        if(dbg==1 && i%28==0) getch();
    }
    return 0;
}

