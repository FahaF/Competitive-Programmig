// topic  : Digit Dp
// Everything you do is to maximize your pleasure

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s[11];
ll m,n,tc = 1;
ll dp[12][12];

ll sol(ll pos,ll prv)
{
    if(pos >= n)return 1;

    if(dp[pos][prv] != -1)return dp[pos][prv];
    ll val = 0;

    for(ll i = 0 ; i < m; i++)
    {
        if(pos)
        {
            if(abs(prv-s[i]) <= 2)
            {
                val += sol(pos+1,s[i]);
            }
        }
        else
        {
            val += sol(pos+1,s[i]);
        }
    }

    return dp[pos][prv] = val;
}

void input_and_sol()
{

    memset(dp,-1,sizeof dp);

    scanf("%lld",&m);
    scanf("%lld",&n);

    for(ll i=0; i<m; i++)scanf("%lld",&s[i]);

    ll ans = sol(0,0);

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

