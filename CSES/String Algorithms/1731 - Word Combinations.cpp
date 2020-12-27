// topic : trie + dp

// for substring (l,r) of the original string if it presents in the
// dictionary  then ans is dp[r] = dp[r] + dp[l-1]
// Used trie to check substring (l,r) present or not

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

struct node
{
    bool ed;
    ll cnt[30];
};

node trie[1000008];
ll dp[5009];

ll ct=1;

void add(string s)
{
    ll st = 1,i;

    for(i=0; i<s.size(); i++)
    {
        if(trie[st].cnt[s[i]-'a'] == 0)
        {
            trie[st].cnt[s[i]-'a'] = ++ct;

        }
        st = trie[st].cnt[s[i]-'a'];
    }
    trie[st].ed = true;

    return;
}

int main()
{
    ll i,j,k,l,m,sz,n,st;

    string s,tp;


    cin >> s;

    sz = s.size();

    cin >> n;

    for(i=0; i<n; i++)
    {
        cin >> tp;

        add(tp);
    }

    dp[0] = 1;


    for(i=1; i<=sz; i++)
    {
        st = 1;
        for(j=i; j<=sz; j++)
        {
            if(!trie[st].cnt[s[j-1]-'a'])break;

            st = trie[st].cnt[s[j-1]-'a'];

            if(trie[st].ed)
                dp[j] = (dp[j]+dp[i-1])%mod;//for substring (i,j) calculating dp[j]
        }
    }

    cout << dp[sz] << endl;
}
