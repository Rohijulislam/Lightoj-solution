#include<bits/stdc++.h>
using namespace std;
#define lim 100003
#define ll long long int
ll tree[3*lim],lazy[3*lim];

void update(int node,int down,int up,int a,int b,ll value)
{
    if(a>up||b<down) return ;
    if(a<=down&&b>=up)
    {
        tree[node]+=((up-down+1)*value);
        lazy[node]+=value;
        return ;
    }
    update(node*2,down,(up+down)/2,a,b,value);
    update(node*2+1,(down+up)/2+1,up,a,b,value);
    tree[node]=tree[node*2]+tree[node*2+1]+(up-down+1)*lazy[node];
}

ll query(int node,int down,int up,int a,int b,ll carry)
{
 if(a>up||b<down) return 0;
 if(a<=down&&b>=up)
 {
     return tree[node]+carry*(up-down+1);
 }
  return query(node*2,down,(up+down)/2,a,b,carry+lazy[node])+
         query(node*2+1,(down+up)/2+1,up,a,b,carry+lazy[node]);
}

int main()
{
    int t,n,i,q,ch,a,b,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
    scanf("%d%d",&n,&q);
    printf("Case %d:\n",i);
    while(q--)
    {
        scanf("%d",&ch);
        if(ch==0)
        {
            scanf("%d%d%d",&a,&b,&k);
            update(1,1,n,a+1,b+1,k);
        }
        else
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(1,1,n,a+1,b+1,0));
        }
    }
    }
    return 0;
}
