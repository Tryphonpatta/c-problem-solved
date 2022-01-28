#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        bool check = false;
        for(int j=x;j<=y;j++){
            int sum = a[j];
            if(sum==m){
                check = 1;
                cout<<"Yes"<<endl;
//                cout<<x<<" "<<endl;
                break;
            }
            for(int l = j+1;l<=y;l++){
                sum+= a[l];
                if(sum==m){
                    check = 1;
                    cout<<"Yes"<<endl;
//                    cout<<j<<" "<<l<<" : "<<sum<<endl;
                    break;
                }
                if(sum>m)break;
            }
            if(check)break;
        }
        if(!check)cout<<"No"<<endl;
    }


}
