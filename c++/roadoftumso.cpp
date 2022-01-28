#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int main(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int> > > e;
    for(int i=0;i<n;i++){
        int x,y,r;
        cin>>x>>y>>r;
        e.push_back({r,{x,y}});
    }
    sort(e.begin(),e.end());
    for(int i=0;i<e.size();i++){
        cout<<e[i].se.fi<<" "<<e[i].se.se<<" "<<e[i].fi<<endl;
    }
    vector<pair<int,pair<int,int> > > mst;
    bool v[n] = {};
    for(int i=0;i<e.size();i++){
        if(v[e[i].se.fi]==0||v[e[i].se.se]==0){
            mst.push_back(e[i]);
            v[e[i].se.fi]= 1;
            v[e[i].se.se]= 1;
        }
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        cout<<mst[i].se.fi<<" "<<mst[i].se.se<<" "<<mst[i].fi<<endl;
    }
}
