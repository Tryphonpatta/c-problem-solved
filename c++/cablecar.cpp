#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pa pair<int,int>
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > a[n+1];
    for(int i=0;i<m;i++){
        int x,y,r;
        cin>>x>>y>>r;
        a[x].push_back({r,y});
        a[y].push_back({r,x});
    }
    int start,finish,pe;
    cin>>start>>finish>>pe;
    priority_queue<pa > q;
    q.push({INT_MAX,start});
    bool v[n+1] = {};
    while(!q.empty()){
        int t = q.top().s, m = q.top().f;
        q.pop();
        if(v[t]==true)continue;
        v[t] = true;
        if(t==finish){
            cout<<ceil((float)pe/(m-1));
            return 0;
        }
        for(int i=0;i<a[t].size();i++){
            q.push({min(m,a[t][i].f),a[t][i].s});
        }

    }


}
