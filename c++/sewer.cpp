#include<bits/stdc++.h>
using namespace std;
int n,m;
bool an = false;
int Min = INT_MAX;
int x,y;
char a[101][101] = {};
set<int> b[101][101];
bool vis[101][101] = {};
int ans(int i,int j,int cnt){
    if(i<0||j<0||i>=n||j>=m||vis[i][j]){
        return 0;
    }
    if(b[i][j].find(cnt)!=b[i][j].end()){
        if(cnt<Min){
            Min = cnt;
            x = i;
            y= j;
        }
    }
    b[i][j].insert(cnt);
    vis[i][j] = 1;
    if(a[i][j]=='N'){
    }
    if(a[i][j]=='R'){
        ans(i,j+1,cnt+1);
    }
    else if(a[i][j]=='D'){
        ans(i+1,j,cnt+1);
    }
    else if(a[i][j]=='B'){
        ans(i+1,j,cnt+1);
        ans(i,j+1,cnt+1);
    }
    if(j-1>=0&&(a[i][j-1]=='R'||a[i][j-1]=='B'))ans(i,j-1,cnt+1);
    if(i-1>=0&&(a[i-1][j]=='D'||a[i-1][j]=='B'))ans(i-1,j,cnt+1);
    vis[i][j] = 0;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    ans(0,0,1);
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout<<b[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<Min<<endl<<x+1<<" "<<y+1;

}
