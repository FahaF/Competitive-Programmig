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
#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MAX        15000
#define         max5        100000
#define         max6        1000000
#define         mod       1000000007
ll power(ll a, ll n){ll res = 1;while (n > 0) {if (n & 1) {res = (res*a)%mod;}a = (a*a)%mod;n = n/2;}return res;}
int main()
{
    ll i,j,k,l,m,n;

    cin >> n;

    string s;

    cin >> s;

    m = s.size();

    ll ans = 0;

    for(i=0;i<=n-m;i++)
    {
        ans = (ans + (2ll*power(26ll,n-m))%mod)%mod;
    }

    cout << ans << endl;
}
