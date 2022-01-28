#include<iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int a,b;
    int u[5]={};

    for(int i=1;i<=n;i++){
    a = i%10;
    b = i%100;

    if(i/100==4){
        //cout<<"CD";
    }
    else{
        for(int y =1;y<=i/100;y++){
            //cout<<"C";
            u[4]++;
        }
    }
    if(i%100>=90){
        //cout<<"XC";
        u[4]++;
        u[2]++;
    }
    else{
        if(b>=50){
            //cout<<"L";
            u[3]++;
            for(int y = 1;y<=b/10-5;y++){
                //cout<<"X";
                u[2]++;
            }
        }
        else {
            if(b>=40){
                //cout<<"XL";
                u[2]++;
                u[3]++;
            }
            else {
                for(int y = 1;y<=b/10;y++){
                    //cout<<"X";
                    u[2]++;
                }
            }
        }

    }
    if(a==9){
        //cout<<"IX";
        u[0]++;
        u[2]++;
    }
    else{
        if(a>=5){
           // cout<<"V";
            u[1]++;
            for(int y =1;y<=a-5;y++){
                //cout<<"I";
                u[0]++;
            }
        }
        else {
            if(a==4){
                //cout<<"IV";
                u[0]++;
                u[1]++;
            }
            else {
                for(int y = 1;y<=a;y++){
                    //cout<<"I";
                    u[0]++;
                }
            }
        }
    }
    //cout<<endl;
    }
    for(int i =0;i<5;i++){
        cout<<u[i]<<" ";
    }
}
