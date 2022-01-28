#include<bits/stdc++.h>
using namespace std;
vector<bool> ans;
int main(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(q--){
        int s,x,y,e;
        cin>>s>>e>>x>>y;
        if(s==e){
            ans.push_back(0);
            continue;
        }
        swap(a[x-1],a[y-1]);
//        for(int i=0;i<n;i++){
//            cout<<a[i]<<" ";
//        }
//        cout<<endl;
        int check = 0;
        if(a[s-1]==s){
            ans.push_back(1);
//            cout<<"SURVIVE"<<endl;
            swap(a[x-1],a[y-1]);
            continue;
        }
        else {
            int j = a[s-1]; //j=4;
            while(s!=j){
//                cout<<j<<endl;
                if(j==e){
                    check =1;
                    break;
                }
                j = a[j-1];
            }
        }
        if(check == 1)ans.push_back(0);
        else ans.push_back(1);
        swap(a[x-1],a[y-1]);
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i])cout<<"SURVIVE"<<endl;
        else cout<<"DEAD"<<endl;
    }

}
