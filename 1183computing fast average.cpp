#include<bits/stdc++.h>
using namespace std;
#define sz 100000
#define ll long long
#define gcd(a,b) __gcd(a,b)
struct seg
{
    ll sum,lazy;

}tree[4*sz+9];

void create(int node,int st,int en)
{
    if(st==en)
    {
        tree[node].sum=0;
        tree[node].lazy=-1;
        return ;
    }
    int mid=(st+en)/2;
    create(node*2,st,mid);
    create(node*2+1,mid+1,en);

    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
    tree[node].lazy=-1;
}

void pushdown(int node,int st,int en)
{
    int mid=(st+en)/2;
        //cout<<"push :  "<<st<<"  "<<en<<"\n";
    if(tree[node].lazy!=-1)
    {
        //cout<<st<<"   "<<en<<" -> yeah"<<"\n";

    tree[node*2].lazy=tree[node*2+1].lazy=tree[node].lazy;

    tree[node*2].sum=(mid-st+1)*tree[node].lazy;
    tree[node*2+1].sum=(en-mid)*tree[node].lazy;
    tree[node].lazy=-1;
    }
}


void update(int node,int st,int en,int i,int j,int val)
{
   if(st>j||en<i)
    return;
    if(st>=i&&en<=j)
    {
        tree[node].sum=(en-st+1)*val;
        tree[node].lazy=val;
        return ;
    }
    int mid=(st+en)>>1;
         pushdown(node,st,en);
         update(node*2,st,mid,i,j,val);
         update(node*2+1,mid+1,en,i,j,val);
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}


ll query(int node,int st,int en,int i,int j)
{
    if(st>j||en<i)
        return 0;
    if(st>=i&&en<=j)
    {
        //cout<<st<<"  "<<en<<"\n";
        return tree[node].sum;
    }
   pushdown(node,st,en);
   int mid=(st+en)>>1;
        ll p1=query(node*2,st,mid,i,j);
        ll p2=query(node*2+1,mid+1,en,i,j);
      tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
  return p1+p2;
}


int main()
{
    int n,q,i,t,cs=0,ty,l,r,val;
    ll res,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
          create(1,1,n);
        printf("Case %d:\n",++cs);
        while(q--)
        {
            scanf("%d %d %d",&ty,&l,&r);
            l++;r++;
            if(ty==1)
            {
                scanf("%d",&val);
                update(1,1,n,l,r,val);
            }
           else
           {
               res=query(1,1,n,l,r);
               a=(r-l+1);
               b=gcd(a,res);
               a/=b;
               res/=b;
               if(a==1) printf("%lld\n",res);
               else     printf("%lld/%lld\n",res,a);
           }
        }
    }

    return 0;
}
