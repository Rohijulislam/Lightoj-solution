#include<bits/stdc++.h>
using namespace std;
#define lim 100003

int arr[lim],tree[lim*3];

void build(int node,int down,int up)
{
    if(down==up){   tree[node]=arr[up];return ;  }
   int left=node*2;
   int right=left+1;
   build(left,down,(down+up)/2);
   build(right,(down+up)/2+1,up);
   tree[node]=tree[left]+tree[right];
}
int query(int node ,int down,int up,int m,int n)
{
    if(m>up||n<down)
        return 0;
    if(m<=down&&n>=up)
        return tree[node];
        int left=node*2;   int right=left+1;  int mid=(up+down)/2;
           int p1=query(left,down,mid,m,n);
           int p2=query(right,mid+1,up,m,n);
           return p1+p2;
}

void update(int node,int down,int up,int k,int value)
{
  if(k>up||k<down) return ;
  if(k<=down&&k>=up)
  {
      if(value)
      tree[node]+=value;
      else
        tree[node]=0;
      return ;
  }
  int left=node*2;  int right=left+1;   int mid=(down+up)/2;
  update(left,down,mid,k,value);
  update(right,mid+1,up,k,value);
  tree[node]=tree[left]+tree[right];
}

int main()
{
    int t,i,n,p,a,b,c,j;
    scanf("%d",&t);
    for(p=1;p<=t;p++)
    {

    scanf("%d%d",&n,&j);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n);
    printf("Case %d:\n",p);
    while(j--)
    {

    scanf("%d",&c);
    if(c==1)
    {
        scanf("%d",&a);
       printf("%d\n",query(1,1,n,a+1,a+1));
        update(1,1,n,a+1,0);
    }
    else if(c==2)
    {
        scanf("%d%d",&a,&b);
        update(1,1,n,a+1,b);
    }
    else
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",query(1,1,n,a+1,b+1));
    }
    }
    }
    return 0;
}
