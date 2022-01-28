#include<iostream>
#include<stdio.h>
using namespace std ;
int main(){
    int n;
    float Max= -1;
    cin>>n;
    int i,j,k;
    float a[n],b[n];
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){
                float sum ;
                sum = ((a[i]*b[j]+a[j]*b[k]+a[k]*b[i])-(b[i]*a[j]+b[j]*a[k]+b[k]*a[i]))/2;
                //printf("\n%d %d %d  =  %.2f\n",i,j,k,sum);
                if(sum<0)sum=-sum;
                if(sum>=Max)Max=sum;
            }
        }
    }
    printf("%.3f",Max);
}
