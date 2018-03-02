#include<bits/stdc++.h>
using namespace std;
#define sz 1429431
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

int arr[sz],p1[50009],p2[50009],qu[50009],tree[3*sz];
  map<int,int>um;

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
}

void create(int n,int s,int e)
{
    if(s==e)
    {
        tree[n]=s%2;
        return ;
    }
    int m=(s+e)>>1;
    create(n<<1,s,m);
    create((n<<1)|1,m+1,e);
    tree[n]=tree[n<<1]+tree[(n<<1)|1];
}


int query(int n,int s,int e,int val)
{

    if(s==e)
    {
        return s;
    }
    int m=(s+e)/2;
    if(tree[n<<1]>=val)
    return query(n<<1,s,m,val);
    else
    return query((n<<1)|1,m+1,e,val-tree[n<<1]);
}


void update(int n,int s,int e,int val)
{
   if(s==e)
    {
        tree[n]==0;
        return ;
    }
    int m=(s+e)>>1;
    if(tree[n<<1]>=val) update(n<<1,s,m,val);
    else       update((n<<1)|1,m+1,e,val-tree[n<<1]);
    tree[n]--;
}


int main()
{
    int t,i,j,q,cs=0,val,a=0,b,k=0;
    create(1,1,sz);
    for(i=2;i<100001;i++)
    {
     b=query(1,1,sz,i);
     k=sz/b;k*=b;
     while(k>0)
     {
     update(1,1,sz,k);
     k-=b;
     }
    }
    scan(t);
    while(t--)
    {
        scan(val);
        printf("Case ");
        output(++cs);
        printf(": ");
        output(query(1,1,sz,val));
        printf("\n");
    }
    return 0;
}



