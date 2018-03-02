#include<bits/stdc++.h>
using namespace std;
#define sz 100005
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
char arr[sz];
struct cal
{
 int sum,lazy;
}tree[3*sz];

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
inline void output(int x) {
    int cnt = 0;
    do {
        int y = x/10;
        buf[cnt++] = x - 10*y + '0';
        x = y;
    } while (x);
    while (cnt--) putchar(buf[cnt]);
    putchar('\n');
}


void create(int n,int s,int e)
{
    if(s==e)
    {
        tree[n].sum=arr[s-1]-'0';
        tree[n].lazy=0;
        return;
    }
    int mid=(s+e)>>1;
    create(n<<1,s,mid);create((n<<1)|1,mid+1,e);
    tree[n].lazy=0;
}

int query(int n,int s,int e,int i,int k)
{
    if(s==i&&i==e)
    {
        k+=tree[n].lazy;
        if(k%2==0)
            return tree[n].sum;
        else
        {
            return (tree[n].sum+1)%2;
        }
    }

    int m=(s+e)>>1;
     if(m>=i) return query(n<<1,s,m,i,k+tree[n].lazy);

     else
        return query((n<<1)|1,m+1,e,i,k+tree[n].lazy);
}


void update (int n,int s,int e,int i,int j)
{
    if(s>j||e<i)
        return ;

    if(s>=i&&e<=j)
    {
         tree[n].lazy++;
         return ;
    }
     int mid=(s+e)>>1;
    update(n<<1,s,mid,i,j);
    update((n<<1)|1,mid+1,e,i,j);

}


int main()
{
    int t,i,j,n,q,pos,cs=0,ty,val,a,b;
    char ch;
    scan(t);
    while(t--)
    {
        scanf("%s",arr);
        n=strlen(arr);
      create(1,1,n);
      scan(q);
      printf("Case %d:\n",++cs);
      while(q--)
      {
          ch=getchar();
          scan(i);
          if(ch=='I')
          {
              scan(j);
              update(1,1,n,i,j);
          }
          else
            output(query(1,1,n,i,0));
      }
    }

    return 0;
}




