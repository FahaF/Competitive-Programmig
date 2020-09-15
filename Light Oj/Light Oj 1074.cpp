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

#define         MAX         309

vector<pii>ad[MAX];
bool vis[MAX];
bool isring[MAX];
int dis[MAX];
int cnt[MAX];

void dfs(int u)
{
    isring[u] = true;

    for(auto x : ad[u])
    {
        if(!isring[x.F])
        {
            dfs(x.F);
        }
    }
}

int main()
{
    int i,j,k,l,m,n,u,v,t,tc=1,w,q,ke,qu;

    sf(t);

    while(t--)
    {
       
        sf(n);
        int ar[n+10];

        for(i=1; i<=n; i++)
        {
           sf(ar[i]);
        }
        sf(m);

        for(i=0; i<m; i++)
        {
            sf(u);
            sf(v);
            w = (ar[v]-ar[u]);
            w = w*w*w;

            ad[u].pb({v,w});

        }

        for(i=1; i<=n; i++)dis[i] = INT_MAX;
        dis[1] = 0;
        vis[1] = true;
        queue<int>q;
        q.push(1);

        while(!q.empty())
        {
            u = q.front();

            q.pop();

            vis[u] = false;

            for(auto x : ad[u])
            {
                if(isring[x.F])continue;

                if(dis[u]+x.S < dis[x.F])
                {
                    dis[x.F] = dis[u]+x.S;
                    if(!vis[x.F])
                    {
                        q.push(x.F);
                        vis[x.F] = true;
                        cnt[x.F]++;
                        if(cnt[x.F]>n)dfs(x.F);
                    }
                }
            }
        }

        sf(qu);
        printf("Case %d:\n",tc);

        while(qu--)
        {
            sf(ke);
            if(isring[i] || dis[ke] == INT_MAX || dis[ke]<3)printf("?\n");

            else  printf("%d\n",dis[ke]);

        }
        tc++;

         for(i=1;i<=n;i++)if(ad[i].size())ad[i].clear();
        for(i=1; i<=n; i++)vis[i]=isring[i]=false,cnt[i]=0;
    }
}
