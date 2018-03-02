#include<bits/stdc++.h>
using namespace std;
#define sz 200005
#define FOR(i,a,b) for (int i=(a); i < b; i++)
#define REP(i,n)     FOR(i,0,n)
#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define ll           long long
#define si(n)        scanf("%d", &n);
#define sil(n)       scanf("%I64d", &n);
#define pf(n)        printf("%d\n", n);
#define pl(n)        printf("%I64d\n",n);
#define pii pair<int,int>
#define pll pair<ll,ll>

const int N = 1e5 + 100;
const double eps = 1e-7;
const double PI = acos(-1.0);

int p1[sz],p2[sz],tree[3*sz],ans,k;
template<class T>
inline bool scan(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

char buf[40];
inline void output(int x)
{
    int cnt = 0;
    do
    {
        int y = x/10;
        buf[cnt++] = x - 10*y + '0';
        x = y;
    }
    while (x);
    while (cnt--) putchar(buf[cnt]);
    putchar('\n');
}

void update(int n,int s,int e,int i,int j)
{
    if(s>j||e<i)
        return ;
    if(s>=i&&e<=j)
    {
        if(tree[n])
        return ;

        if(k==0){ans++;k++;}
        tree[n]++;
        return ;
    }
    int m=(s+e)>>1;
    if(tree[n]==0)
    {
    update(n<<1,s,m,i,j);
    update((n<<1)|1,m+1,e,i,j);
    }
    if(tree[n<<1]!=0&&tree[(n<<1)|1]!=0)
      tree[n]++;

}


int main()
{
    int t,i,j,n,q,pos,cs=0,ty,val,cn=0,a=0,b=0;
    scan(t);
    while(t--)
    {
        scan(n);
        memset(tree,0,sizeof(tree));
        ans=0;
        for(i=0; i<n; i++)
        {
            scan(p1[i]);scan(p2[i]);

        }
        printf("Case %d: ",++cs);
        for(i=n-1;i>=0;i--)
        {
            k=0;
            update(1,1,sz-2,p1[i],p2[i]);
        }
        output(ans);
    }
    return 0;
}



