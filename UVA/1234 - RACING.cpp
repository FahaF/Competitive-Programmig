//maximum spanning tree


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MAX        250000
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

ll par[MAX];


ll finD(ll x)
{
    if(x == par[x])return x;

    return par[x] = finD(par[x]);

}

void unioN(ll x,ll y)
{
    ll a,b;

    a = finD(x);
    b = finD(y);

    if(a!=b)
    {
        if(a>b)swap(a,b);
        par[b] = a;
    }

    return;
}


int main()
{
    ll i,j,t,k,l,m,n,u,v,w,ans;
    ll tc = 1;

    cin>>t;

    while(t--)
    {
        cin >> n >> m;

        ans = 0;

        pair<ll,pll>p[m+10];

        for(i=1;i<=n;i++)par[i] = i;

        for(i=0; i<m; i++)
        {
            cin >> u >> v >> w;

            p[i] = {w,{u,v}};
        }

       sort(p,p+m);
       reverse(p,p+m);


       for(i=0;i<m;i++)
       {
           u = p[i].S.F;
           v = p[i].S.S;
           w = p[i].F;


           if(finD(u)!=finD(v))
           {
               unioN(u,v);

           }
           else ans += w;
       }

       cout <<ans << endl;

       tc++;
    }

    cin >> t;
}

