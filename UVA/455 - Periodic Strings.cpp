#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        string s;

        cin >> s;

        vector<int>prefix  = prefix_function(s);

        int n = s.size();
        int m = n-prefix[n-1];

        if(n%m)cout << n << endl;
        else cout << m << endl;
        if(t)puts("");

    }
}

