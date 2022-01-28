#include<iostream>
using namespace std;
int main(){
    int a[3] = {1,0,0};
    string b;
    cin>>b;
    for(int i = 0 ;i<b.size();i++){
        if(b[i]=='A'){
            int temp = a[0];
            a[0]=a[1];
            a[1]=temp;
        }
        if(b[i]=='B'){
            int temp = a[1];
            a[1]=a[2];
            a[2]=temp;
        }
        if(b[i]=='C'){
            int temp = a[0];
            a[0]=a[2];
            a[2]=temp;
        }
    }
    for(int i=0;i<3;i++){
        if(a[i]==1){
            cout<<i+1;
            break;
        }
    }

}
