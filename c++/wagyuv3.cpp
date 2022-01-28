#include<bits/stdc++.h>
using namespace std;
int dp[5000][5000] = {};
int a[100000];
int n,m,q;
int solve(int l,int r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int sum = a[l];
    sum += solve(l+1,r);
    if(sum>m)return 0;
    dp[l][r] = sum;
    return dp[l][r];
}
int main(){

    cin>>n>>m>>q;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i][i] = a[i];
    }
    for(int i =0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        bool check = false;
        for(int j=x;j<=y;j++){
            for(int k=j+1;k<=y;k++){
                solve(j,k);
                if(dp[j][k]==m){
                    check = true;
                    cout<<"Yes"<<endl;
                    break;
                }
            }
            if(check)break;
        }
        if(!check)cout<<"No"<<endl;
//        for(int j=0;j<n;j++){
//            for(int k=0;k<n;k++){
//                cout<<dp[j][k]<<" ";
//            }
//            cout<<endl;
//        }
    }
    return 0;


}
