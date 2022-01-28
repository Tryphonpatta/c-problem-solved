#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> w;
    int score[k] = {};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        w.push_back(x);
    }
    int curr = 0;
    int h = n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        curr = (curr+x)%h;
        score[i%k]+=w[curr];
        w.erase(w.begin()+curr);
        h--;
    }
    for(int i=0;i<k;i++){
        cout<<score[i]<<endl;
    }
}
