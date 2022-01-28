#include<bits/stdc++.h>
using namespace std;
int m,n;
char a[30][30];
int drop(int b,int n){
    while(b--){
        int i;
        for(i=0;i<m;i++){
            if(a[i][n]=='#'||a[i][n]=='O'){
                break;
            }
        }
        if(i>0){
            a[i-1][n] = '#';
        }
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        drop(b,i);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }



}
