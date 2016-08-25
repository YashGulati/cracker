#include<stdio.h>
#include<string.h>
#include<math.h>
char charset[] = "abcd";
int length = 3;
int wc=0;
int wordCount(charlen,wordlen){
    if(wordlen == 1) return strlen(charset);
    return pow(strlen(charset),wordlen) + wordCount(charlen,wordlen-1);
}
int main(){
    int i,total_words, dbg=0;
    int pos[10],flag[10];
    int charset_length = strlen(charset);
    void printer(){
        int p;
        for(p=length;p>=2;p--)
            if(flag[length-p]!= -1) printf("%c",charset[pos[length-p]]);
        printf("%c\n",charset[pos[length-1]++]);
    }
    memset(pos,-1,sizeof(pos));
    memset(pos,0,length*4);
    memset(flag,-1,sizeof(flag));

    total_words = wordCount(charset_length,length);
    for(i=0;i<total_words;i++){
        if(dbg==1) printf("%d: ",i);
         if( length>=1 ){ // if#1
            if(pos[length-1] == charset_length ){
                pos[length-1] = 0;
                if(pos[length-2] != -1 ){
                    if(flag[length-2] ==2 ) pos[length-2]++;
                    flag[length-2] = 1;
                }
            }
         }
         if( length>=2 && flag[length-2]!= -1 ){ // if#2
            flag[length-2] = 2;
            if(pos[length-2] == charset_length ){
                pos[length-2] = 0;
                if(pos[length-3] != -1 ){
                    if(flag[length-3] ==2 ) pos[length-3]++;
                    flag[length-3] = 1;
                }
            }
        }
        if( length>=3 && flag[length-3]!= -1 ){ // if#3
            flag[length-3] = 2;
            if(pos[length-3] == charset_length ){
                pos[length-3] = 0;
                if(pos[length-4] != -1 ){
                    if(flag[length-4] ==2 ) pos[length-4]++;
                    flag[length-4] = 1;
                }
            }
        }
        if( length>=4 && flag[length-4]!= -1 ){ // if#3
            flag[length-4] = 2;
            if(pos[length-4] == charset_length ){
                pos[length-4] = 0;
            }
        }
        printer();
    }
    return 0;
}

