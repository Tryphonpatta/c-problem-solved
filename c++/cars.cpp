#include<bits/stdc++.h>
using namespace std;
bool a[101][41]={};
int ans[101];
int n,t;
int re(int index,int m){
    if(m<0||m>=n||a[index][m])return 0;
    if(index==t){
        for(int i=0;i<t;i++){
            cout<<ans[i]<<endl;
        }
        return 1;
    }

    ans[index] = 1;
    re(index+1,m-1);
    ans[index] = 2;
    re(index+1,m+1);
    ans[index] = 3;
    re(index+1,m);
}
int main(){
    int start;
    cin>> n>>start>>t;
    for(int i=1;i<=t;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    re(0,start-1);




}
