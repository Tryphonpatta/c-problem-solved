#include<bits/stdc++.h>
using namespace std;
int main(){
    char o;
    cin>>o;
    string a,b;
    cin>>a>>b;
    vector<int> p,q;
        int lv = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='(')lv++;
            else if(a[i]==')')lv--;
            else if(a[i]==',')p.push_back(lv);
        }
        lv = 0;
        for(int i=0;i<b.size();i++){
            if(b[i]=='(')lv++;
            else if(b[i]==')')lv--;
            else if(b[i]==',')q.push_back(lv);
        }
        for(int i=0;i<p.size();i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<q.size();i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    if(o =='i'){
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            for(int j=0;j<q.size();j++){
                if(q[j]==p[i]){
                    ans.push_back(q[j]);
                    q[j] = 0;
                    p[i] = 0;
                    break;
                }
                else if(abs(q[j]-p[i])>2){
                    break;
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
        int l =0;
        for(int i=0;i<ans.size();i++){
            if(l<ans[i]){
                while(l<ans[i]){
                    cout<<'(';
                    l++;
                }
            }
            else if(l>ans[i]){
                while(l>ans[i]){
                    cout<<')';
                    l--;
                }
            }
            cout<<',';
        }
        while(l>0){
                cout<<')';
                l--;
        }
    }

}
