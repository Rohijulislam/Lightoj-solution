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
   int lazy, c1,c2,c3;
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
        tree[n].c3=1;tree[n].c2=0;tree[n].c1=0;tree[n].lazy=0;
        return ;
    }

    int mid=(s+e)>>1;
    create(n<<1,s,mid);create((n<<1)|1,mid+1,e);
    tree[n].c3=tree[n<<1].c3+tree[(n<<1)|1].c3;
    tree[n].c2=0;tree[n].c1=0;tree[n].lazy=0;

}


int query(int n,int s,int e,int i,int j,int k)
{
    if(s>j||e<i)
        return 0;
    if(s>=i&&e<=j)
    {
       k%=3;
       if(k==0)
        return tree[n].c3;
        else if(k==1) return tree[n].c2;
        else    return tree[n].c1;
    }

    int m=(s+e)>>1;
      return query(n<<1,s,m,i,j,k+tree[n].lazy)+query((n<<1)|1,m+1,e,i,j,k+tree[n].lazy);
}


void update (int n,int s,int e,int i,int j)
{
    if(s>j||e<i)
        return ;

    if(s>=i&&e<=j)
    {
        tree[n].lazy++;
        tree[n].lazy%=3;
        int temp=tree[n].c3;
        //cout<<tree[n].c3<<"  oi  "<<s<<"  "<<" "<<e<<"  ki -> ";
        tree[n].c3=tree[n].c2;
        tree[n].c2=tree[n].c1;
        tree[n].c1=temp;
        //cout<<"up: "<< tree[n].c3<<"  "<< tree[n].c2<<" "<< tree[n].c1<<"\n";
         return ;
    }
     int mid=(s+e)>>1;
    update(n<<1,s,mid,i,j);
    update((n<<1)|1,mid+1,e,i,j);

    int la=tree[n].lazy;
    la%=3;
    if(la==0)
    {

    tree[n].c3=tree[n<<1].c3+tree[(n<<1)|1].c3;
    tree[n].c2=tree[n<<1].c2+tree[(n<<1)|1].c2;
    tree[n].c1=tree[n<<1].c1+tree[(n<<1)|1].c1;
    }
    else if(la==1)
    {
    tree[n].c3=tree[n<<1].c2+tree[(n<<1)|1].c2;
    tree[n].c2=tree[n<<1].c1+tree[(n<<1)|1].c1;
    tree[n].c1=tree[n<<1].c3+tree[(n<<1)|1].c3;
    }
    else if(la==2)
    {
    tree[n].c3=tree[n<<1].c1+tree[(n<<1)|1].c1;
    tree[n].c2=tree[n<<1].c3+tree[(n<<1)|1].c3;
    tree[n].c1=tree[n<<1].c2+tree[(n<<1)|1].c2;
    }

}


int main()
{
    int t,i,j,n,q,pos,cs=0,ty,val,a,b;
    scan(t);
    while(t--)
    {
        scan(n);
      create(1,1,n);
      scan(q);
      printf("Case %d:\n",++cs);
      while(q--)
      {
          scan(ty);
          scan(i);scan(j);

          if(ty==0)
          {
              update(1,1,n,i+1,j+1);
          }
          else
            output(query(1,1,n,i+1,j+1,0));
      }
    }

    return 0;
}





