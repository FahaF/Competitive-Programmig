
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
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define        sqr(a)       ((a)*(a))

#define         MAX         10007

vi ad[MAX];
bool vis[MAX];
int low[MAX],in[MAX],intime;
int parent[MAX],cnt[MAX];

map<pii,int>bridge,era;

int find(int x)
{
    if(x == parent[x])return x;

    return parent[x] = find(parent[x]);
}

void dfs(ll x,ll par)
{
    vis[x] = 1;

    intime++;

    low[x] = in[x] = intime;

    for(auto child : ad[x])
    {

        if(child == par) continue;

        if(vis[child])
        {
            low[x] = min(low[x],in[child]);
        }
        else
        {

            dfs(child,x);

            low[x] = min(low[x],low[child]);

            if(low[child] > in[x])
            {
//                cout << "Bridge  " << x << " " << child << endl;
//                cout << "see  " << in[x] << " " << low[child] << endl;
                bridge[ {x,child}] = bridge[ {child,x}] = 1;
                era[ {x,child}]=1;
            }


        }
    }
}

int main()
{
    int i,j,k,l,m,n,u,v,t,tc=1;

    sf(t);

    while(t--)
    {
        sf(n);
        sf(m);

        for(i=0; i<m; i++)
        {
            sf(u);
            sf(v);

            ad[u].pb(v);
            ad[v].pb(u);
        }


        intime = 0;
        for(i=0;i<n;i++)if(!vis[i])dfs(i,-1);

        for(i=0; i<n; i++)parent[i] = i;

        for(i=0; i<n; i++)
        {
            for(auto x : ad[i])
            {
                if(bridge[ {i,x}])continue;

                u = find(i);
                v = find(x);

                if(u!=v)
                {
                    parent[u] = v;
                }

            }
        }

        for(auto x : era)
        {
            u = find(x.F.F) , v = find(x.F.S);

            cnt[u]++;
            cnt[v]++;
        }
        int leaves = 0;

        for(i=0; i<n; i++)
        {
            leaves += (cnt[i]==1);
        }


        leaves = (leaves+1)/2;


        printf("Case %d: %d\n",tc,leaves);
        tc++;

        for(i=0;i<n;i++)ad[i].clear();
        bridge.clear();
        era.clear();
        for(i=0;i<n;i++)vis[i]=false,cnt[i]=in[i]=low[i]=0;
    }
}





