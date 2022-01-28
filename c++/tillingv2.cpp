#include<bits/stdc++.h>
using namespace std;
int a[20][20];
vector<int> posx,posy;
int t;
int ans = 0;
int x=0,y=0;
int check(int i,int j,int n,int t){
    if(i<0||j<0||i>=n||j>=n||a[i][j]==-1||a[i][j]!=t){
        return 0;
    }
    a[i][j] = -1;
    if(j+1<n&&a[i][j+1]==t){
        check(i,j+1,n,t);
        x++;
    }
    if(i+1<n&&a[i+1][j]==t){
        check(i+1,j,n,t);
        y++;
    }
    if(i-1>=0&&a[i-1][j]==t){
        check(i-1,j,n,t);
        y++;
    }
    if(j-1>=0&&a[i][j-1]==t){
        check(i,j-1,n,t);
        x++;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x=0;y=0;
            check(i,j,n,a[i][j]);
            if(x==1&&y==1){
                ans++;
            }
        }
    }
    cout<<ans;
}
