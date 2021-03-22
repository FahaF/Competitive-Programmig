#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MAX        200003
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
    ll i,j,k,l,m,n,u,v,w,ans=0,bl,wh,t,tot=0;

    bl = wh = 0;

    cin >> n >> m >> k;

    ans = 0;

    pair<ll,pll>sada[m+10];
    pair<ll,pll>kalo[m+10];

    for(i=1; i<=n; i++)par[i] = i;

    for(i=0; i<m; i++)
    {
        cin >> u >> v >> w >> t;

        if(t==1)
            sada[wh] = {w,{u,v}},wh++;
        else kalo[bl] = {w,{u,v}},bl++;
    }

    sort(sada,sada+wh);

    if(wh < k)return cout << -1 << endl,0;

    for(i=0; i<wh; i++)
    {
        u = sada[i].S.F;
        v = sada[i].S.S;
        w = sada[i].F;
        if(finD(u)!=finD(v))
        {
            unioN(u,v);

            ans += w;

            tot++;

        }
        if(tot == n-1 || tot == k)break;
    }

    if(tot<n-1)
    {
        sort(kalo,kalo+bl);

        for(i=0; i<bl; i++)
        {
            u = kalo[i].S.F;
            v = kalo[i].S.S;
            w = kalo[i].F;
            if(finD(u)!=finD(v))
            {
                unioN(u,v);
                ans += w;
                tot++;
            }

        }

    }

    if(tot != n-1)ans = -1;

    cout <<ans << endl;


}


