#include<stdio.h>
#include<string.h>
int main(){
    char a[1000],b,c[10000];
    gets(a);
    scanf("%c ",&b);
    gets(c);
    int a1 = strlen(a),c1=strlen(c),i;
    if(b=='+'){
        if(a[0]=='0')printf("%s",c);
        else if(c[0]=='0')printf("%s",a);
        else if(a1>c1){
            a[a1-c1] = '1';
            printf("%s",a);
        }
        else if(a1==c1){
            printf("2");
            for(i=1;i<=a1-1;i++)printf("0");
        }
        else{
            c[c1-a1] = '1';
            printf("%s",c);
        }
    }
    else if(b=='*'){
        if(a1==1)printf("%s",c);
        else if(c1==1)printf("%s",a);
        else {
        printf("%s",a);
        for(i=1;i<=c1-1;i++){
            printf("0");
        }
        }
        }
}
