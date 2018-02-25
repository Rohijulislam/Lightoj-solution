#include<cstdio>
using namespace std;
int n;

int cal(int k)
{
    int res=0;
    while(k>0)
    {
        res+=(k/5);
        k/=5;
    }
    return res;
}

void bs()
{
 int lo=1,hi=400000029,mid,k;
 while(lo<hi)
{
    mid=lo+(hi-lo)/2;
    k=cal(mid);
    if(k==n)
        break;
  if(k>n)
    hi=mid-1;
  else
    lo=mid+1;
}
if(k==n)  printf("%d\n",mid-mid%5);
else             printf("impossible\n");

}
int main()
{
 int t,i,res;
   scanf("%d",&t);
   for(i=1;i<=t;i++)
   {
     scanf("%d",&n);
     printf("Case %d: ",i);
     bs();
   }
}
