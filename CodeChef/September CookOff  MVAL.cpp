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
        cin >> n ;

        ll ar[n+10];

        ll sum = 0;

        ll ct[n+10];

        memset(ct,0,sizeof ct);

        for(i=0;i<n;i++)
        {
            cin >> ar[i];


            if(ar[i] > 0)sum+=ar[i],ct[i]=1;
        }

        for(i=n-2;i>=0;i--)ct[i] += ct[i+1];

        set<ll>fin;

        for(i=0;i<n;i++)
        {
            if(ar[i] < 0)fin.insert(i);

            if(i<n-1 && fin.size() == ct[i+1] && ct[i+1])
            {

                for(j=n-1;j>=i;j--)
                {
                    if(ar[j]>0)
                    fin.insert(j);
                }
                break;
            }
        }

        cout << sum << endl;
        cout << fin.size() << " ";
        for(auto x : fin)cout<<x+1<<" ";

        cout <<endl;





    }
}

