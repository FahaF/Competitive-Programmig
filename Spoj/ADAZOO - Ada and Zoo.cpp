#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll id[20];

void initialize()
{
    for(ll i = 0;i < 20;++i)
        id[i] = i;
}

ll root(ll a)
{
    while(id[a] != a)
    {
        id[a] = id[id[a]];
        a = id[a];
    }
    return a;
}

void union1(ll a, ll b)
{
    ll p = root(a);
    ll q = root(b);
    id[p] = id[q];
}

ll x[12],y[12];
ll d[20][20][20][20];

ll sol(vector<ll>nodes)
{
    ll sz = nodes.size();

    vector<pair<ll,pair<ll,ll>>>ad;

    for(ll i=0;i<sz-1;i++)
    {
        for(ll j=0;j<sz;j++)
        {
            if(i==j)continue;
            cout << "culp " << x[nodes[i]] <<"   " << y[nodes[i]] << " " << x[nodes[j]] <<" " << y[nodes[j]] << " " <<  d[x[nodes[i]]][y[nodes[i]]][x[nodes[j]]][y[nodes[j]]] << endl;
            ad.push_back({d[x[nodes[i]]][y[nodes[i]]][x[nodes[j]]][y[nodes[j]]],{i,j}});

        }
    }

    // kruskal

    initialize();
    sort(ad.begin(),ad.end());

    ll u,v,cost,minimumCost=0;
//cout << " somossha " <<sz <<  endl;
    for(ll i=0;i<ad.size();i++)
    {
        u = ad[i].second.first;
        v = ad[i].second.second;
        cost = ad[i].first;
        if(root(u) != root(v))
        {
            minimumCost += cost;
            union1(u,v);
        }
    }

    return minimumCost;
}
int main()
{
    ll i,j,k,l,m,n,q;

    cin >> n ;

    ll ar[n+10][n+10];

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >>  ar[i][j];
        }
    }

    for (int k1 = 0; k1 < n; ++k1)
    {
        for (int k2 = 0; k2 < n; ++k2)
        {
            for (int i1 = 0; i1 < n; ++i1)
            {
                for (int i2 = 0; i2 < n; ++i2)
                {
                    for (int j1 = 0; j1 < n; ++j1)
                    {
                        for (int j2 = 0; j2 < n; ++j2)
                        {
                            d[i1][i2][j1][j2] = 1000009;
                        }
                    }
                }
            }
        }
    }

    for (int k1 = 0; k1 < n; ++k1)
    {
        for (int k2 = 0; k2 < n; ++k2)
        {
            for (int i1 = 0; i1 < n; ++i1)
            {
                for (int i2 = 0; i2 < n; ++i2)
                {
                    for (int j1 = 0; j1 < n; ++j1)
                    {
                        for (int j2 = 0; j2 < n; ++j2)
                        {
                            ll hisab = abs(i1-j1)+abs(i2-j2);
                            if(hisab<=1)d[i1][i2][j1][j2] = min(d[i1][i2][j1][j2],abs(ar[i1][i2]-ar[j1][j2]));
                            else
                                d[i1][i2][j1][j2] = min(d[i1][i2][j1][j2], d[i1][i2][k1][k2] + d[k1][k2][j1][j2]);

                            //  cout << i1 << " " << i2 << "  " << j1<< " " << j2 << " " << " eta  " << d[i1][i2][j1][j2] << endl;

                        }
                    }
                }
            }
        }
    }

    cin >> q;


    for(i=0; i<q; i++)
    {
        cin >> x[i] >> y[i];
    }

   // cout << " oka" << (1ll<<q) << endl;

    ll ans = 0;

    for(ll mask = 1; mask<(1ll<<q); mask++)
    {
        vector<ll>nodes;

        for(j=0; j<q; j++)
        {
            if((mask&(1ll<<j)))
            {
                nodes.push_back(j);
            }
        }

        if(nodes.size()>1){

        cout << " node " << nodes.size() << " " << sol(nodes) << endl;

        for(auto xx : nodes)cout << "Era  " << x[xx] << " " << y[xx] << endl;
        ans += sol(nodes);
        }
    }


    cout << ans << endl;

}

