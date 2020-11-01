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
    int i,j,k,l,m,n,tst;

    sf(tst);

    while(tst--)
    {


        sf(n);

        int ar[n+10];
        int br[n+10];

        memset(br,0,sizeof br);

        for(i=0; i<n; i++)sf(ar[i]);

        for(i=0; i<n; i++)
        {
            if(__gcd(ar[i],ar[i+1])!=1)
            {
                br[i] = br[i+1] = 1;
            }
        }

        if(__gcd(ar[0],ar[n-1])!=1)br[0]=br[n-1]=1;


        int ct = 0;
        vi v;



        for(i=0; i<n; i++)if(br[i]==0)break;

        for(; i<n; i++)
        {
            if(br[i] == 1)ct++;
            else
            {
                if(ct)v.pb(ct);
                ct = 0;
            }
        }

        for(i=0; i<n; i++)
        {
            if(br[i]==1)ct++;
            else
            {
                if(ct)
                    v.pb(ct);
                ct=0;
                break;
            }
        }

        if(ct) v.pb(ct);

        map<int,int>kota;

        for(auto x : v)
        {
            kota[x]++;
        }

        for(i=2; i<=n; i++)
        {
            int ans = 0;

            for(auto x : kota)
            {

                m = x.F;
                ct = x.S;


                ans += ct*(((m+i-2)/(i-1))-1);

                if(m==i)ans++;

            }

            printf("%d ",ans) ;

        }

        cout << endl;




    }
}


