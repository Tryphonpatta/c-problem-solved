#include<iostream>
using namespace std;
int main(){
    int n,m,x;
    cin>>n>>m;
    char a[m][n];
    for(int i = 0 ; i < m ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < m ; i++){
        int l = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(a[i][j]!=a[i+1][j]){
                l++;
            }
        }
        x=i;
        if(l>2){
            x =i;
            break;
        }
    }
    for(int j=0;j<n;j++){
        cout<<a[x][j];
    }

}
