#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b=0;
    char a[4] = {'E','N','W','S'};
    int x=0,y=0;
    while(n--){
        string d;
        int c;
        cin>>d>>c;
        if(d=="LT"){
            b=b+1;
        }
        else if(d=="RT"){
            b=b+3;
        }
        else if(d=="FD"){
        }
        else if(d=="BW"){
            b=b+2;
        }
        b=b%4;
        if(a[b]=='E'){
            x+=c;
        }
        else if(a[b]=='W'){
            x-=c;
        }
        else if(a[b]=='N'){
            y+=c;
        }
        else if(a[b]=='S'){
            y-=c;
        }
        if(x>=50000||y>=50000||x<=-50000||y<=-50000){
            cout<<"DEAD";
            return 0;
        }
    }
    cout<<x<<" "<<y<<endl;
    cout<<a[b];


}
