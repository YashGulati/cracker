#include<stdio.h>
int main(){
    //FILE *f1 = fopen("./test.txt", "w");
    int h,i,j,k,l,temp;
    char charset[] = "abcd";
    int maxlength =  3 ;
    int over3 = maxlength - 3;
    int scope = 0;
    for(k=0,i = 0; i<=maxlength-1; i++) {
        printf("%c",charset[k]);
    }
    printf("\n");
for(k=0;k<strlen(charset)-2;k++){
    for(i=0; i<=maxlength-2; i++)
        printf("%c",charset[k]);
    for(i=0;i<=maxlength-3-over3;i++)
        printf("%c",charset[k+1]);
    printf("\n");
    for(i = 0; i<=maxlength-3; i++)
        printf("%c",charset[k]);
    for(i = 0; i<=maxlength-2-over3; i++)
        printf("%c",charset[k+1]);
    printf("\n");
    for(i = 0; i<=maxlength-1; i++)
        printf("%c",charset[k+1]);
    printf("\n");
}
for(i = 0; i<=maxlength-2; i++) {
        printf("%c",charset[k]);
    }
    printf("%c",charset[k+1]);
    printf("\n");
    for(i = 0; i<=maxlength-3; i++) {
        printf("%c",charset[k]);
    }
    for(i = 0; i<=maxlength-2-over3; i++) {
        printf("%c",charset[k+1]);
    }
    printf("\n");
    for(i = 0; i<=maxlength-1; i++) {
        printf("%c",charset[k+1]);
    }
    return 0;
}
