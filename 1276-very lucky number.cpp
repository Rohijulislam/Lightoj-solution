#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define lim  1000000000000
#define pb push_back
set<ll>
int main()
{
    int i,k=2,j=0,kp;
    ll a,p;
    luc.pb(4);luc.pb(7);
    for(i=0;i<k;i++)
    {
        p=10*luc[i];
        if(p+4<=lim)
            luc.pb(p+4),k++,ck[p+4]=1;
        if(p+7<=lim)
            luc.pb(p+7),k++,ck[p+7]=1;
          else
                break;
    }
    for(i=0;i<k;i++)
    {
        for(j=i;j<k;j++)
        {
            p=luc[i]*luc[j];
            if(ck[p]==1||p>lim);

            else
            k++;
        }
    }
    //cout<<k<<endl;
    return 0;
}
