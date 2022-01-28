#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> q[n+1];
    map<int,int> ma;
    map<int,int> ro;
    int la[m+1] ={};
    for(int i=0;i<n;i++){
        int r;
        ll s1;
        int a;
        scanf("%d",&a);
        scanf("%d %lld",&r,&s1);
        q[la[r]].push_back(a);
        la[r]++;
        ma[a] = s1;
        ro[a] = r;
    }
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<q[i].size();j++){
//            cout<<q[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl<<endl;
        for(int i=0;q[i].size();i++){
            ll max = INT_MIN,ans=INT_MAX,roans=INT_MAX;
            for(int j=0;j<q[i].size();j++){
                if(max<=ma[q[i][j]]){
                    if(roans<ro[q[i][j]]&&max==ma[q[i][j]]){
                        continue;
                    }
                    else {
                        ans = (q[i][j]);
                        roans = ro[q[i][j]];}
                        max = ma[q[i][j]];
                    }
            }
            cout<<ans<<endl;
        }



}
