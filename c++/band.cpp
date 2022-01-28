#include<bits/stdc++.h>
using namespace std;
bool rela[1001][1001] = {};
int ans = 0;
int combination(int a[],int temp[],int i,int in,int n){
    if(in==4){
//        for(int i=0;i<4;i++){
//            cout<<temp[i]<<" ";
//       }
        int bad =0;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                if(!rela[temp[i]][temp[j]]){
                    bad++;
                }
            }
        }
        if(bad<=1)ans++;
//        cout<<bad;
//        cout<<endl;
        return 0;
    }
    if(i>=n)return 0;
    temp[in] = a[i];
    combination(a,temp,i+1,in+1,n);
    combination(a,temp,i+1,in,n);

}
int main(){
    int n,m;
    bool ch[1001] = {};
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        ch[x] = 1;
        ch[y] = 1;
        rela[x][y] = 1;
        rela[y][x] = 1;
    }
    vector<int> a;
    int y = n;
    for(int i=0;i<n;i++){
        if(ch[i+1])a.push_back(i+1);
        else y--;
    }
    n = y;
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=n;j++){
//            cout<<rela[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int temp[4];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(ch[a[i]]&&ch[a[j]]&&ch[a[k]]&&ch[a[l]]){
                    int sum =0;
                    if(!rela[a[i]][a[j]])sum++;
                    if(!rela[a[i]][a[k]])sum++;
                    if(sum>1)continue;
                    if(!rela[a[i]][a[l]])sum++;
                    if(sum>1)continue;
                    if(!rela[a[j]][a[k]])sum++;
                    if(sum>1)continue;
                    if(!rela[a[j]][a[l]])sum++;
                    if(sum>1)continue;
                    if(!rela[a[k]][a[l]])sum++;
                    if(sum<=1)ans++;
                    }
                }
            }
        }
    }
    cout<<ans;

}
