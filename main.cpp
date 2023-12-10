#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
char a1[50001]={0},b1[50001]={0};
int a[50001]={0},b[50001]={0},c[50001]={0};
int i,j,k;
int main()
{
    cin>>a1>>b1;
    a[0]=strlen(a1);
    b[0]=strlen(b1);
    for(i=1;i<=a[0];i++)a[i]=a1[a[0]-i]-'0';
    for(i=1;i<=b[0];i++)b[i]=b1[b[0]-i]-'0';
    for(i=1;i<=a[0];i++)for(j=1;j<=b[0];j++)c[i+j-1]+=a[i]*b[j];
    c[0]=a[0]+b[0];
    for(k=1;k<=c[0];k++)
    if(c[k]>9)
    {
        c[k+1]+=c[k]/10;c[k]%=10;
    }
    while(c[c[0]]==0&&c[0]>1)c[0]--;
    for(k=c[0];k>=1;k--)cout<<c[k];
    return 0;
}
