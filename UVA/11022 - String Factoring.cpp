// Topic : KMP + DP;


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll prefix_function(string s)//kmp prefix function
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

ll dp[200][200];
string str;
ll cal(ll i,ll j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==j)return 1;
    dp[i][j] = 0x3f3f3f3f;

    for(ll k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j],cal(i,k)+cal(k+1,j));
    }
    ll len = j-i+1;
    ll m = len - prefix_function(str.substr(i,len));

    if(len%m == 0)
    {
        dp[i][j] = min(dp[i][j],cal(i,i+m-1)) ;
    }

    return dp[i][j];

}

int main()
{
    int t,i,j;

    while(1)
    {

        cin >> str;

        if(str == "*")break;

        memset(dp,-1,sizeof dp);


        cout << cal(0,str.size()-1) << endl;
    }
}
