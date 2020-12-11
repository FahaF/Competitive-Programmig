// topic  : Digit Dp
// leave and come

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ar[33];
ll dp[33][2][2][32];
ll tc=1;

ll sol(ll pos,ll is_small,ll prv,ll tot)
{
    if(pos >= 32)return tot;
    if(dp[pos][is_small][prv][tot]!=-1)return dp[pos][is_small][prv][tot];

    ll val = 0,low = 0,high = ar[pos];

    if(is_small)high = 1;

    for(ll i = low ;i <= high;i++)
    {
        if(prv && i)
        {
            val += sol(pos+1,is_small | i<ar[pos],i,tot+1);
        }
        else
        {
            val += sol(pos+1,is_small | i<ar[pos],i,tot);
        }
    }

    return dp[pos][is_small][prv][tot] = val;

}
void input_and_sol()
{

    memset(dp,-1,sizeof dp);

    ll n,i,j=0;

    scanf("%lld",&n);


    for(i=31;i>=0;i--)
    {
        if((1ll<<i)&n)
        {
            ar[j] = 1;
        }
        else ar[j] = 0;

        j++;
    }

    ll ans = sol(0,0,0,0);

    printf("Case %lld: %lld\n",tc,ans);
    tc++;

}
int main()
{
    ll t;

    scanf("%lld",&t);

    while(t--)
    {
        input_and_sol();
    }

    return 0;
}


