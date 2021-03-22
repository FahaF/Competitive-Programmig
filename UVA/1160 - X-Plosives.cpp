#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MAX        100009
#define         max5        100000
#define         max6        1000000
#define         mod       1000000007
#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'

int par[MAX];

ll finD(ll x)
{
    if(x==par[x])return x;

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

    return ;
}
int main()
{
    int i,j,k,l,m,n,tc=0,t,u,v,cnt=0;


    for(i=0; i<=100000; i++)par[i]=i;

    while(scanf("%d",&u)!=EOF)
    {

        if(u==-1)
        {
            pf(cnt);
            cnt = 0;
            for(i=0;i<=100000;i++)par[i]=i;
            continue;
        }

        scanf("%d",&v);

        int a,b;

        a = finD(u);
        b = finD(v);

        if(a==b)
        {
            cnt++;
        }
        else unioN(u,v);
    }
}
