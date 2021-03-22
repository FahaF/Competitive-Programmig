#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MAX       600
#define         max5        100000
#define         max6        1000000
#define         mod       1000000007
#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ei(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)

ll id[MAX];
ll finD(ll x)
{
    if(x == id[x])return x;

    return id[x] = finD(id[x]);

}

void unioN(ll x,ll y)
{
    ll a,b;

    a = finD(x);
    b = finD(y);

    if(a!=b)
    {
        if(a>b)swap(a,b);
        id[b] = a;
    }

    return;
}

vector<pll>ad[MAX];
ll L[MAX];
ll up[MAX][20];
ll dp[MAX][20];
ll limit,n,m;
pair<ll,pll>p[209];
bool taken[MAX];
void init()
{
    for(ll i=1; i<=n; i++)
    {
        ad[i].clear();
    }

    memset(dp,-1,sizeof dp);
    memset(up,-1,sizeof up);
    memset(L,0,sizeof L);
    memset(taken,false,sizeof taken);
}
void dfs(ll u,ll par,ll d)
{
    up[u][0] = par;
    L[u] = d;
    for(auto x : ad[u])
    {
        if(x.F!=par)
        {
            dp[x.F][0] = x.S;
            dfs(x.F,u,d+1);
        }
    }
}
void lca_init()
{
    dfs(1,-1,0);

    for(ll j=1; (1ll<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            if(up[i][j-1]!=-1)
            {

                dp[i][j] = max(dp[i][j-1],dp[up[i][j-1]][j-1]);
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
}
ll lca_query(ll u,ll v)
{
    ll ans = 0;

    if(L[u]<L[v])swap(u,v);

    limit = log2(n)+2;

    for (ll i = limit-1; i >= 0; i--)
    {
        if (L[u] - L[v] >= (1 << i))
        {
            ans = max(ans,dp[u][i]);
            u = up[u][i];
        }
    }

    if(u==v)return ans;

    for(ll i=limit-1; i>=0; i--)
    {
        if (up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i])
        {
            ans = max(ans, max(dp[u][i], dp[v][i]));
            u = up[u][i];
            v = up[v][i];
        }
    }

    ans = max(ans, max(dp[u][0], dp[v][0]));
    return ans;

}
int main()
{
    ll i,j,k,t,mst,u,v,w,tc=1;


    cin >> t;

    while(t--)
    {

        ll tot = 0;
        cin >> n >> m;

        for(i=0; i<m; i++)
        {
            cin >> u >> v >> w;
            p[i] = {w,{u,v}};
        }

        for(i=1; i<=n; i++)id[i] = i;
        mst = 0;

        sort(p,p+m);

        for(i=0; i<m; i++)
        {
            u = p[i].S.F;
            v = p[i].S.S;
            w = p[i].F;

            if(finD(u)!=finD(v))
            {
                unioN(u,v);
                ad[u].pb({v,w});
                ad[v].pb({u,w});
                // cout << "eta " << u << " " << v<< " " << w << endl;
                taken[i] = true;
                mst += w;
                tot++;
            }
        }

        lca_init();

        vl mstv;

        mstv.pb(mst);



        for(i=0; i<m; i++)
        {
            if(!taken[i])
            {
                u = p[i].S.F;
                v = p[i].S.S;
                w = p[i].F;
                ll mx = lca_query(u,v);
                mstv.pb(mst-mx+w);
            }
        }
        printf("Case #%lld : ",tc);
        tc++;
        if(tot!=n-1)
        {
            printf("No way\n");
        }
        else if(mstv.size()==1)
        {
            printf("No second way\n");
        }
        else
        {
            sort(all(mstv));
            printf("%lld\n",mstv[1]);
        }


        init();

    }
}
