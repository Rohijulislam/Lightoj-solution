#include<bits/stdc++.h>
using namespace std;
#define lim 100003
int arr[lim],tree[lim*3];


int  merge(int a,int b)
{
    int mi=100000000,ma=0,i;
    for(i=a;i<=b;i++)
    {
        if(arr[i]>ma) ma=arr[i];
        if(arr[i]<mi) mi=arr[i];
    }
    return ma-mi;
}


void build(int node,int down,int up,int k)
{
    if(up==down)
    {
        tree[node]=arr[up];
        return ;
    }
    int left=node*2;int right=left+1;int mid=(up+down)/2;
    build(left,down,mid,k);
    build(right,mid+1,up,k);
    if(up-down<k)
        tree[node]=merge(down,up);
    else
        tree[node]=max(tree[left],tree[right]);

}

int main()
{
    int n,i,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n,k);
    for(i=1;i<=20;i++)
        cout<<tree[i]<<endl;
    return 0;
}
