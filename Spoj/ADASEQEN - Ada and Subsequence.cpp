// Just LCS

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s,t;

ll dp[2001][2001];
ll co[2001];

ll cal(ll i,ll j)
{
    if(i>=s.size()||j>=t.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans = 0;

    if(s[i]==t[j])
    {
        ans = max(ans,ans+co[s[i]-'a']+cal(i+1,j+1));
    }

    ll ans1=0,ans2=0;
    if(i+1<s.size())
    ans1 = max(ans1,ans1+cal(i+1,j));
    if(j+1<t.size())
    ans2 = max(ans2,ans2+cal(i,j+1));

    return dp[i][j] = max({ans,ans1,ans2});
}
int main()
{
    ll i,j,k,l,m,n;

    cin >> n >> m ;

    for(i=0;i<26;i++)cin >> co[i];

    cin >> s >> t;

    memset(dp,-1,sizeof dp);

    cout<<cal(0,0)<<endl;
}
