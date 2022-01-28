#include<bits/stdc++.h>
using namespace std;
int n;
double a[21][21];
double dp[1<<21];
double find(int d,int j){
    if(d==n)return 1;
    if(dp[j]!=-1)return dp[j];
    dp[j] = INT_MIN;
    for(int i=0;i<n;i++){
        dp[j] = max(dp[j],a[d][i]*find(d+1,(j|1<<i)));
    }
    return dp[j];

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double temp;
            cin>>temp;
            a[i][j] = temp/100;
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<find(0,0);

}
