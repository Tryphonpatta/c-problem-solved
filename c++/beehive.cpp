#include<bits/stdc++.h>
using namespace std;
int n,m;
int ma = INT_MIN;
int a[1000][1001]={};
int b[1000][1001] = {};
int findmax(int i,int j){
    if(i%2==0){
        if(j==0){b[i][j] = b[i-1][j];return a[i-1][j];}
        else {
            if(a[i-1][j]==a[i-1][j-1])b[i][j] = b[i-1][j]+b[i-1][j-1];
            else if(a[i-1][j]>a[i-1][j-1]){
                b[i][j] =  b[i-1][j];
            }
            else {
                b[i][j] =  b[i-1][j-1];
            }
            return max(a[i-1][j],a[i-1][j-1]);
        }
    }
    else{
        if(a[i-1][j]==a[i-1][j+1])b[i][j] = b[i-1][j]+b[i-1][j+1];
        else if(a[i-1][j]>a[i-1][j+1]){
            b[i][j] = b[i-1][j];
        }
        else {
            b[i][j] = b[i-1][j+1];
        }
        return max(a[i-1][j],a[i-1][j+1]);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(i==0)b[0][j] = 1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] += findmax(i,j);
        }
    }
    for(int j=0;j<m;j++){
        ma = max(ma,a[n-1][j]);
    }
    int ans =0;
    for(int j=0;j<m;j++){
        if(ma==a[n-1][j]){
            ans+=b[n-1][j];
        }
    }
    cout<<ma<<" "<<ans;
}
