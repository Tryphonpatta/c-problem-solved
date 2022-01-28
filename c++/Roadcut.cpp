#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int r[150]={},c[150]={},co=0,pr=0;
    int rp[150]={},cp[150]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            r[i]+= x;
            c[j]+= x;
            co+= x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            rp[i]+= x;
            cp[j]+= x;
        }
    }
    int maxx = 0,maxy = 0;
    for(int i=1;i<=n;i++){
        if(maxx<co-r[i]+rp[i-1]+rp[i+1]){
            maxx = co-r[i]+rp[i-1]+rp[i+1];
        }
    }
    for(int i=1;i<=m;i++){
        if(maxy<co-c[i]+cp[i-1]+cp[i+1]){
            maxy = co-c[i]+cp[i-1]+cp[i+1];
        }
    }
    cout<<max(maxx,maxy);


}
