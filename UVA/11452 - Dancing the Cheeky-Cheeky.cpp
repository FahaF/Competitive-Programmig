// Topic : KMP


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll prefix_function(string s)
{
    ll n = (ll)s.size(),j;
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n-1];
}

int main()
{
    int t,i,j;


    cin >> t;


    while(t--)
    {

        string str;
        cin >> str;


        ll n = str.size();
        ll m = n-prefix_function(str);
        ll rem = n%m;
        string fin = str.substr(0,m);
        string ans = "";
        ll tt = 8;
        ll i = rem;
        while(tt--)
        {
            ans += fin[i];
            i++;
            i%=m;
        }

        ans += "...";


        cout << ans << endl;
    }
}

