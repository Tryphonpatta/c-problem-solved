#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>
#define f first
#define s second
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > v[n];
    int sta,fn,mo;
    cin>>sta>>fn>>mo;
    for(int i=0;i<m;i++){
        int x,y,r;
        cin>>x>>y>>r;
        v[x].push_back({y,r});
        v[y].push_back({x,r});
    }
    int ans = INT_MAX;
    vector<int> last;
    int ans2 =INT_MAX;
    int l = 0;
    priority_queue< pair<int,pair<int,pair<int,int> > > , vector<pair<int,pair<int,p > > >,greater<pair<int,pair <int,p> > > > q;
    q.push({0,{sta,{-1,0}}});
    bool vis[n] = {};
    bool check = false;
    int a1,b1,c1;
    while(!q.empty()){
        int m = q.top().f;
        int t = q.top().s.f;
        int l = q.top().s.s.f;
        int u = q.top().s.s.s;
        q.pop();
        if(t==fn){
            if(m<=mo){
                ans = min(ans,m);
                check = true;
                c1 = 0;
            }
            else if(!check){
                if(m>mo){
                last.push_back(l);
                    if(u<=ans2){
                        a1 = l;
                        ans2 = min(u,ans2);
                        ans = m;
                    }
                }
            }
        }
        if(vis[t]==true)continue;
        vis[t] = true;
        for(int i=0;i<v[t].size();i++){
            if(!vis[v[t][i].f]){
                if(m+v[t][i].s<=mo)q.push({m+v[t][i].s,{v[t][i].f,{v[t][i].f,u}}});
                else {
                    q.push({m+v[t][i].s,{v[t][i].f,{l,u+v[t][i].s}}});
                }
//                  q.push({ m+v[t][i].s,{ v[t][i].f,{ t , u } } });
            }
        }
    }
    if(check){
        cout<<fn<<" "<<ans<<" "<<0;
    }
    else {
//        for(int i=0;i<last.size();i++){
//            cout<<last[i]<<endl;
//        }
        cout<<a1<<" "<<-ans2+ans<<" "<<ans2;
    }
//    for(int i=0;i<last.size();i++){
//        cout<<last[i]<<endl;
//    }
}
