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
        cin >> n >> k ;

        string s;

        ll kata = 0;

        cin >> s;

        for(i=0;i<n-1;i++)if(s[i]!=s[i+1])kata++;

        if(k>=kata)cout << 0 << endl;
        else
        {
            vl bk;
            ll  cnt = 0,st=-1,ed=-1;
            for(i=0;i<n;i++)
            {
                if(s[i]=='0')cnt++;
                else
                {
                    if(cnt)bk.pb(cnt);
                    if(st==-1)st = cnt;
                    cnt = 0;
                }
            }
            if(cnt)
            {
                bk.pb(cnt);
                ed = cnt;
            }

            sort(all(bk));
            reverse(all(bk));

            ll ans=0;

            for(i=0;i<bk.size();i++)
            {
                //cout << bk[i] << endl;
                if(k>=1 && (bk[i]==st || bk[i]==ed))
                {
                    k--;
                    if(bk[i]==st)st=-1;
                    else if(bk[i]==ed)ed=-1;
                }
                else if(k>=2)
                {
                    k-=2;
                }
                else ans+=bk[i];


            }

            cout << ans << endl;
        }



    }
}

