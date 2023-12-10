#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[2001]={0},b[2001]={0},sum[4001]={0},temsum[4001]={0};
int size=0,tempsize=0;

int main()
{int i,j;
int sa,sb;
    //get a
    char get;
    get=cin.get();
    for(i=0;get!='\n';i++)
    {
        a[i]=get-'0';
        get=cin.get();
    }
    sa=i;
    //get b
    get=cin.get();
    for(i=0;get!='\n';i++)
    {
        b[i]=get-'0';
        get=cin.get();
    }
    sb=i;
    size=sb;
    for(i=0;i<sa/2;i++)
    {
        int tem=a[i];
        a[i]=a[sa-1-i];
        a[sa-1-i]=tem;
    }
    for(i=0;i<sb/2;i++)
    {
        int tem=b[i];
        b[i]=b[sb-1-i];
        b[sb-1-i]=tem;
    }

//fun
    for(i=0;i<sa;i++)
    {tempsize=sb;
        for(j=0;j<sb;j++)//乘
            temsum[j]=b[j]*a[i];
        for(j=0;j<tempsize;j++)//进位
            if(temsum[j]>9){if(j==tempsize-1){temsum[j+1]=0;tempsize=sb+1;}temsum[j+1]+=temsum[j]/10;temsum[j]%=10;}
        //问题出在这
        for(j=0;j<tempsize;j++)//temp加到sum里
        {
            sum[i+j]=sum[i+j]+temsum[j];
            if(i+j+1>size)size=i+j+1;
        }
        for(j=0;j<size;j++)
        {
            if(sum[j]>9){sum[j+1]+=sum[j]/10;sum[j]%=10;if(j==size-1)size++;}
        }
    }
    for(i=4001;i>=0;i--)
    {
        if(sum[i]!=0)break;
    }
    for(;i>=0;i--)cout<<sum[i];
    return 0;
}
