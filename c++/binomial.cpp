#include<bits/stdc++.h>
using namespace std;
int main(){
    int n =10;
    int a[10][10];
    for(int i=0;i<=9;i++){
        a[i][0] = 1;
        for(int j=1;j<i;j++){
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
        a[i][i] = 1;
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=i;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
