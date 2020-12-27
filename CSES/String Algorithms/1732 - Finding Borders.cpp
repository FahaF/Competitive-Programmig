#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'

int z[1000009];

int main()
{
    int i,j,k,l,m,n;
    string s;
    cin >> s;
    n = s.size();
    z[0] = n;
    int L = 0, R = 0;
    for (i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n &&s[R-L] == s[R]) R++;
            z[i] = R-L;
            R--;
        }
        else
        {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else
            {
                L = i;
                while (R < n &&s[R-L] == s[R]) R++;
                z[i] = R-L;
                R--;
            }
        }
    }

    set<ll>st;

    for(i=1; i<n; i++)
    {
        if(z[i] == (n-i))st.insert(z[i]);
    }

    for(auto x : st)cout << x << " ";

    cout << endl;
}
