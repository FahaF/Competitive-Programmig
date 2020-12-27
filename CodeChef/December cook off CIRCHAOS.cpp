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
#define         all(c)     c.begin(),c.end()

int main()
{
    ll i,j,k,l,m,n,t;

    cin >> t;

    while(t--)
    {
        cin >> n;

        cin >> m;

        ll ar[m+10],g;


        for(i=0;i<m;i++)
        {
            cin >> ar[i];

            if(!i)g = ar[i];
            else g = __gcd(g,ar[i]);
        }


        vector<ll>tmp;

        for(j=1;j*j<=g;j++)
        {
            if(g%j==0)
            {
                tmp.pb(j);

                if(j != (g/j))tmp.pb(g/j);
            }


        }


        sort(all(tmp));

        ll let = upper_bound(all(tmp),n)-tmp.begin();

        ll ans = 0;

        let--;

        if(let>=0)
        {
            ans = n-tmp[let];
        }

        cout << ans << endl;

    }
}
