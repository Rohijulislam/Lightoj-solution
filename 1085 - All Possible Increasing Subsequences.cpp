#include<bits/stdc++.h>
using namespace std;
#define sz 100005
#define mod 1000000007
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

int tree [3*sz];
struct cal
{
    int val,pos;
}arr[sz];

bool cmp(cal a,cal b)
{

    if(a.val==b.val)
        return a.pos>b.pos;
    else
        return a.val<b.val;
}


void create(int n,int s,int e)
{
    if(s==e)
    {
        tree[n]=0;
        return;
    }
    int m=(s+e)/2;
    create(n<<1,s,m);create((n<<1)|1,m+1,e);
    tree[n]=0;
}


void update(int n,int s,int e,int i,int val)
{
    if(s>i||e<i)
        return;

    if(s==i&&e==i)
    {
        tree[n]=val;
        return;
    }
    int m=(s+e)>>1;
    update(n<<1,s,m,i,val);
    update((n<<1)|1,m+1,e,i,val);
    tree[n]=(tree[n<<1]+tree[(n<<1)|1])%mod;
}


int query(int n,int s,int e,int i,int j)
{
    if(s>j||e<i)
        return 0;
    if(s>=i&&e<=j)
        return tree[n];

    int m=(s+e)/2;
    return (query(n<<1,s,m,i,j)+query((n<<1)|1,m+1,e,i,j))%mod;
}


int main()
{
    int t,i,j,n,cs=0,val,a=0,b=0;
    scan(t);
    while(t--)
    {
        scan(n);
        create(1,1,n);
        for(i=0; i<n; i++)
        {
            scan(arr[i].val);
            arr[i].pos=i+1;

        }

        sort(arr,arr+n,cmp);
        REP(i,n)
        {
            a=arr[i].pos;
            b=query(1,1,n,1,a);
            update(1,1,n,a,b+1);
        }
        printf("Case ");
        output(++cs);
        printf(": ");
        output(tree[1]);
        printf("\n");

    }
    return 0;
}



