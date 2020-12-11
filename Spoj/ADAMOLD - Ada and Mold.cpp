#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define       MAX          8015

const ll inf=0x3f3f3f3f;

ll dp[2][MAX];
ll cost[MAX][MAX];
ll cnt[MAX][35];
ll ar[MAX];

ll sol(ll i,ll j)
{
    ll zero,one,sum=0;

    for(ll l=0;l<32;l++)
    {
        one = cnt[j][l]-cnt[i-1][l];
        zero = (j-i+1)-one;

        sum += (one*zero*(1ll<<l));
    }

    return sum;

}

void dnc(ll pos,ll l, ll r, ll optl, ll optr)
{
    if (l > r)return;


    ll mid = (l + r) >> 1;

    ll opt;

    for (ll k = optl; k <= min(mid, optr); k++)
    {
         if(dp[pos][mid]>(dp[pos^1][k] + cost[k+1][mid]))
         {
             dp[pos][mid]  = dp[pos^1][k] + cost[k+1][mid];
             opt = k;
         }
    }

    dnc(pos,l, mid - 1, optl, opt);
    dnc(pos,mid + 1, r, opt, optr);
}

int main()
{
    int tst;

    tst=1;

    while(tst--)
    {

        ll i,j,k,l,m,n;


        sfl(n);
        sfl(k);

        k++;

        for(i=1; i<=n; i++)sfl(ar[i]);


        for(i=1;i<=n;i++)
        {
            for(j=0;j<32;j++)
            {
                cnt[i][j] = cnt[i-1][j];

                if((1ll<<j)&ar[i])cnt[i][j]++;
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                cost[i][j] = sol(i,j);
            }
        }

        memset(dp[0],0x3F,sizeof dp[0]);

        dp[0][0] = 0;

        for(i=1; i<=k; i++)
        {
            memset(dp[i&1], 0x3F,sizeof dp[i&1]);
            dnc(i&1,0,n,0,n);
        }
        pfl(dp[k&1][n]);

    }
}
