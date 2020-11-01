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


int main()
{
    ll i,j,k,l,m,n,tst;

    cin >> tst;

    while(tst--)
    {
        cin >> n >> k >> l;

        m = (n+k-1)/k;


        if(k==1)
        {
            if(n!=1)
            {
                cout << -1 << endl;
                continue;
            }
        }
        if(m>l)cout << -1<<endl;
        else
        {
            ll kt=1;
            for(i=1;i<=n;i++)
            {
                cout << kt << " ";
                kt++;
                if(kt>k)kt=1;
            }

            cout <<endl;
        }
    }
}

