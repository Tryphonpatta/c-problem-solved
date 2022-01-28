#include<bits/stdc++.h>
using namespace std;
int preorder(int i,int n,int tree[]){
    if(i<0||i>=n||tree[i]==-1)return 0;
    cout<<tree[i]<<" ";
    preorder(i*2+1,n,tree);
    preorder(i*2+2,n,tree);
}
int inorder(int i,int n,int tree[]){
    if(i<0||i>=n||tree[i]==-1)return 0;
    inorder(i*2+1,n,tree);
    cout<<tree[i]<<" ";
    inorder(i*2+2,n,tree);
}
int postorder(int i,int n,int tree[]){
    if(i<0||i>=n||tree[i]==-1)return 0;
    postorder(i*2+1,n,tree);
    postorder(i*2+2,n,tree);
    cout<<tree[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int> o[n],bu[n];
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        o[i].push_back(x);o[i].push_back(y);o[i].push_back(z);
    }
    int root  = 0;
    for(int i=0;i<n;i++){
        bool check = true;
        for(int j=0;j<n;j++){
            if(i==j){continue;}
            for(int y=1;y<3;y++){
                    if(o[i][0]==o[j][y]){
                        check = false;
                        break;
                    }
                }
            }
            if(check){
                root = i;
                break;
            }
    }
    cout<<root<<endl;
    swap(o[0],o[root]);
//    for(int i=0;i<n;i++){
//        for(int j=0;j<3;j++){
//            cout<<o[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int a[n] = {};
    memset(a,-1,sizeof a);
    queue<vector<int>> q;
    a[o[0][0]] = 0;
    int tree[60] = {};
    memset(tree,-1,sizeof tree);
    tree[0] = o[0][0];
    int lc = o[0][1],rc = o[0][2];
    if(lc!=-1){
        tree[1] = lc;
        a[lc] = 1;
    }
    if(rc!=-1){
        tree[2] = rc;
        a[rc] = 2;
    }
    for(int i=1;i<n;i++){
        q.push(o[i]);
    }
//    cout<<tree[0]<<" "<<tree[1]<<" "<<tree[2]<<endl;
    while(!q.empty()){
        vector<int> tmp = q.front();
        int pa = q.front()[0];
        int lc = q.front()[1];
        int rc = q.front()[2];
//        cout<<pa<<" "<<lc<<" "<<rc<<endl;
        q.pop();
        if(a[pa]==-1){
            q.push(tmp);
            continue;
        }
        if(lc!=-1){
            a[lc] = a[pa]*2+1;
            tree[a[lc]] = lc;
        }
        if(rc!=-1){
            a[rc] = a[pa]*2+2;
            tree[a[rc]] = rc;
        }
//        cout<<"M"<<endl;
    }
//    for(int i=0;i<60;i++){
//        if(tree[i]!=-1){
//            cout<<tree[i]<<" ";
//        }
//    }
    preorder(0,60,tree);cout<<endl;
    inorder(0,60,tree);cout<<endl;
    postorder(0,60,tree);cout<<endl;
}
