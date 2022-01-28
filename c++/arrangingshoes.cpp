#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n*=2;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int ans =0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]>0){
                for(int j=i+1;j<a.size();j++){
                    if(a[j]<0){
                        a.insert(a.begin()+i,a[j]);
                        a.erase(a.begin()+j+1);
                        ans+=j-i;
                        break;
                    }
                }
            }
        }
        else {
            if(a[i]!=abs(a[i-1])){
                for(int j=i+1;j<a.size();j++){
                    if(a[j]==abs(a[i-1])){
                        a.insert(a.begin()+i,a[j]);
                        a.erase(a.begin()+j+1);
                        ans+=j-i;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    cout<<ans;
}
