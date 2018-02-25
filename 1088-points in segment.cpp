#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[100003];
int main()
{
    int t,n,q,k,i;
    ll a,b,ck;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
            scanf("%lld",&x[i]);
        sort(x,x+n);
        printf("Case %d:\n",k);
       while(q--)
       {
           scanf("%lld%lld",&a,&b);
           a=lower_bound(x,x+n,a)-x;
           ck=lower_bound(x,x+n,b)-x;
           if(x[ck]==b)
            ck++;
           printf("%lld\n",ck-a);
       }
    }

    return 0;
}
