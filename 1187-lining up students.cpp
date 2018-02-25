#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,n,a,ans,k,i;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);
        ans=1;
        scanf("%d",&a);
        for(i=2;i<=n;i++)
        {
            scanf("%d",&a);
            if(i-a<=ans)
                ans++;
        }
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
