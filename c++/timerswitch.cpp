#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    for(int i=1;i<=n;i++){
        if(n%i!=0)continue;
        int check =1;
        for(int j=0;j<n-i;j++){
            if(s[j]!=s[i+j]){check =0;break;}
        }
        if(check){
            cout<<i;
            return 0;
        }
    }
}
