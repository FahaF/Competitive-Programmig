//Floyd Warshall

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MAX        15000
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


int main()
{
    ll i,j,k,l,m,n,u,v,w,q;
    int cs = 1;
    while(1)
    {

        cin >> n >> m >> q;

        if(n+m+q == 0)break;


        ll ans[n+10][n+10];

        for(i=1; i<=n; i++)for(j=1; j<=n; j++)ans[i][j]=1e18;



        for(i=0; i<m; i++)
        {
            cin >> u >> v >> w;
            ans[u][v] = min(ans[u][v],w);
            ans[v][u] = min(ans[v][u],w);
        }


        for (k = 1; k <= n; ++k)
        {
            for (i = 1; i <= n; ++i)
            {
                for (j = 1; j <= n; ++j)
                {

                        ans[i][j] = min(ans[i][j],max(ans[i][k],ans[k][j]));

                }
            }
        }

        if(cs>1)cout<<endl;

        cout << "Case #"<<cs<< endl;


        while(q--)
        {
            cin >> u >> v;

            if(ans[u][v] == 1e18)cout << "no path" << endl;
            else
            {
                cout << ans[u][v] << endl;
            }


        }

        cs++;
    }
}
