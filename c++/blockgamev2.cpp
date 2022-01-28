#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[10000][10000];
bool c = false;
char t;
int point =0;
int check(int x,int y){
    if(x<0||y<0||x>=n||y>=m||a[x][y]!=t)return 0;
    if(a[x][y]==t){c = true; a[x][y] = '-';point+=5;}
    check(x-1,y);
    check(x+1,y);
    check(x,y-1);
    check(x,y+1);
}
int fcheck(int i,int j){
    t = a[i][j];
    if((i>=1&&a[i-1][j]==t)||(i<n-1&&a[i+1][j]==t)||j>=1&&a[i][j-1]==t||j<=m-2&&a[i][j+1]==t){
        check(i,j);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int k;
    cin>> k ;
    while(k--){
        c =false ;
        int x,y;
        char op;
        cin>>x>>y>>op;
        int i,j;
        if(a[x][y]=='-'||a[x][y]=='#'){
            point-=5;
            continue;
        }
        else if(op=='L'){
            if(y>=1&&a[x][y-1]=='-'){
                swap(a[x][y],a[x][y-1]);
                i=x,j=y;
                while(i<=n-2&&a[i+1][j-1]=='-'){
                    swap(a[i+1][j-1],a[i][j-1]);
                    i++;
                }
                j--;
                t = a[i][j];
                fcheck(i,j);
//                cout<<point<<endl;
            }
            else {point-=5;}
        }
        else if(op=='R'){
            if(y<=m-2&&a[x][y+1]=='-'){
                swap(a[x][y],a[x][y+1]);
                i=x,j=y;
                while(i<=n-2&&a[i+1][j+1]=='-'){
                    swap(a[i+1][j+1],a[i][j+1]);
                    i++;
                }
                j++;
                t = a[i][j];
                fcheck(i,j);
//                cout<<point<<endl;
            }
            else {point-=5;}
        }
        while(c){
            c = false;
            bool mint = false;
            for(int ip=0;ip<=n-2;ip++){
                for(int jo=0;jo<m;jo++){
                    if(a[ip][jo]=='-'||a[ip][jo]=='#')continue;
                    int r =ip;
                    while(r<n-1&&a[r+1][jo]=='-'){
                        swap(a[r][jo],a[r+1][jo]);
                        r++;
                        mint = true;
                        c = true;
                    }
//                        cout<<point<<endl;
                }
            }
            for(int i =0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(a[i][j]=='-'||a[i][j]=='#')continue;
                    t = a[i][j];
                    fcheck(i,j);
                }
            }
        }
    }
    cout<<point<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
