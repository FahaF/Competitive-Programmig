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
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))

#define MAX 100008

vl ad[MAX];
ll ar[MAX];
ll ans[MAX];

ll in[MAX];


void d1(ll u,ll p)
{
    for(auto x : ad[u])
    {
        if(x == p)continue;

        d1(x,u);

        in[u] = max(in[u],in[x]+max(0ll,ar[x]-ar[u]));
    }
}



void d2(ll u,ll p,ll parsol)
{

    vl pr,suf;

    for(auto x : ad[u])
    {
        if(x!=p)
        {
            pr.pb(max(0ll,ar[x]-ar[u])+in[x]);
            suf.pb(max(0ll,ar[x]-ar[u])+in[x]);
        }
    }

    ll sz = pr.size(),i;

    for(i=1;i<sz;i++)pr[i] = max(pr[i],pr[i-1]);
    for(i=sz-2;i>=0;i--)suf[i] = max(suf[i],suf[i+1]);

    ll child = 0;

    for(auto x : ad[u])
    {
        if(x == p)continue;

        ll nxtpar =  0;

        if(child>0)
        {
            nxtpar = pr[child-1];
        }
        if(child<sz-1)
        {
            nxtpar = max(nxtpar,suf[child+1]);
        }

        if(p!=-1)
        {
            nxtpar = max(nxtpar,max(0ll,ar[p]-ar[u])+parsol);
        }

        d2(x,u,nxtpar);

        child++;
    }


        if(sz)
        ans[u] = max(ans[u],suf[0]);

        if(p != -1)
        ans[u] = max(ans[u],max(0ll,ar[p]-ar[u])+parsol);

}
int main()
{
    ll i,j,k,l,m,n,u,v,q;

    cin >> n >> q;

    for(i=0; i<n; i++)cin>>ar[i];

    for(i=0; i<n-1; i++)
    {
        cin >> u >> v;
        ad[u].pb(v);
        ad[v].pb(u);
    }

    d1(0,-1);
    d2(0,-1,0);


   // cout << in[5] << endl;

 //  for(i=0;i<n;i++)cout << i << " " << ans[i] << endl;

    while(q--)
    {
        cin >> u;

        cout << ans[u] << endl;
    }

}


