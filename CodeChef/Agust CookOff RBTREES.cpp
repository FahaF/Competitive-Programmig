/*
Offline practice
Topic : Tree , dp ,dfs
Similar problem : https://csacademy.com/contest/algorithms-2018-08-07-18/task/tree_swapping/statement/

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         MAX        100004

vi ad[MAX];
int w1[MAX],w2[MAX],n,ev,od,ans;
string s;

void read()
{

    cin >> n;
    for(int i = 0 ; i<n-1 ; i++)
    {
        int u,v;
        cin >> u >> v;
        ad[u].pb(v);
        ad[v].pb(u);
    }
    cin >> s;
}

void rem()
{
    ev = od = ans = 0;
    for(int i=1; i<=n; i++)
    {
        ad[i].clear();
        w1[i] = w2[i] = 0;
    }
}

void dfs(int u,int p,int d)
{
    if(d&1)od++;
    else ev++;

    for(auto x : ad[u])
    {
        if(x!=p)
        {
            dfs(x,u,d+1);
        }
    }
}

void cal(int  u,int p,int shouldbe)
{
    if(shouldbe == 0 && s[u-1]=='1')w1[u]++;
    if(shouldbe == 1 && s[u-1]=='0')w2[u]++;

    for(auto x : ad[u])
    {
        if(x == p)continue;

        cal(x,u,shouldbe^1);

        w1[u] += w1[x];
        w2[u] += w2[x];

    }

    int mini = min(w1[u],w2[u]);

    w1[u] -= mini;
    w2[u] -= mini;
    ans += w1[u]+w2[u];

}

int main()
{
    int tst;

    cin >> tst;

    while(tst--)
    {

        read();

        int cnt=0;

        for(int i=0; i<n; i++)cnt+=(s[i]-'0');

        dfs(1,-1,0);

        if(ev!=cnt && od!=cnt)
        {
            cout << -1 << endl;
        }
        else
        {

            if(ev==cnt && od==cnt)
            {
                cal(1,-1,1);
                int fin = ans;
                for(int i=1;i<=n;i++)w1[i]=w2[i]=0;
                ans = 0;
                cal(1,-1,0);
                fin = min(fin,ans);
                ans = fin;

            }
            else if(ev==cnt)
            {
                cal(1,-1,1);
            }
            else
            {
                cal(1,-1,0);
            }

            cout << ans << endl;
        }

        rem();
    }
}
