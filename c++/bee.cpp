#include<iostream>
using namespace std;
int main(){
    int w= 1,q=1,s=0;
    while(1){
        int y ;
        cin>>y;
        if(y==-1)break;
        for(int i=1;i<=y;i++){
            int k =w,j=s;
            w+=j;
            s+=k;
            s-=j;
            w++;

        }
        //cout<<q<<" "<<w<<" "<<s;
        cout<<w<<" "<<q+w+s<<endl;
        q = 1;
        w = 1;
        s = 0;
    }

}
