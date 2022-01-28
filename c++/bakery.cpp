#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    float a=0,b=0,c=0,d=0,e=0,ans;
    for(int i=0;i<n;i++){
        int a1,b1,c1,d1,e1;
        cin>>a1>>b1>>c1>>d1>>e1;
        a=a+a1;
        b=b+b1;
        c=c+c1;
        d=d+d1;
        e=e+e1;
    }
    ((int)((a*8)+(b*6)+(c*4)+(d*2)+e)%8 != 0)? cout<<((int)((a*8)+(b*6)+(c*4)+(d*2)+e)/8+1) : cout<<((int)((a*8)+(b*6)+(c*4)+(d*2)+e)/8);
}
