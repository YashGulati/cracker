#include<stdio.h>
#include<string.h>
void struggler(){

}
int main(){
    int i;
    char charset[] = "abcd";
    int length = 3;
    int pos[10],flag[10];
    memset(pos,-1,sizeof(pos));
    memset(pos,0,length*4);
    memset(flag,-1,sizeof(flag));
    for(i=0;i<((strlen(charset)+1)*strlen(charset)-1)+1;i++){

        if(pos[length-3] != -1 && flag[length-3]!= -1 ){
            printf("%c",charset[pos[length-3]]);
            flag[length-3] = 2;
            if(pos[length-3] == strlen(charset) ){ pos[length-3] = 0; if(pos[length-4] != -1 ) pos[length-4]++; }
        }

        if(pos[length-2] != -1 && flag[length-2]!= -1 ){
            printf("%c",charset[pos[length-2]]);
            flag[length-2] = 2;
            if(pos[length-2] == strlen(charset) ){ flag[length-3] = 1;  pos[length-2] = 0; if(pos[length-3] != -1 ) pos[length-3]++; }
        }

        if(pos[length-1] != -1 ){
            printf("%c\n",charset[pos[length-1]]);
            pos[length-1]++;
            if(pos[length-1] == strlen(charset) ){
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
