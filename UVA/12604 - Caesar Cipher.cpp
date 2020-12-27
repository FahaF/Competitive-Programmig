// topic : KMP

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
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         all(c)     c.begin(),c.end()

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

bool searchkmp(string s, int ck)
{
    vi pf = prefix_function(s);

    int i,tt=0;

    for(i=ck+1;i<s.size();i++)
    {
        if(pf[i]==ck)tt++;
    }



    if(tt==1)return true;

    return false;

}
int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        string A,W,s;
        cin >> A ;
        cin >> W ;
        cin >> s ;

        int sz = W.size(),n=A.size(),j,i;

        map<char,int>maap;

        for(i=0;i<n;i++)
        {
            maap[A[i]]  = i;
        }
        string tmp;
        j = 0;
        vi ans;
        while(j<n)
        {
            tmp = "";
            for(i=0; i<sz; i++)
            {
                tmp += A[(maap[W[i]]+j)%n];
            }

            tmp += "#";
            tmp += s;

            if(searchkmp(tmp,sz))
            {
                ans.pb(j);
            }
            j++;

        }


       if(ans.size() == 0)
       {
           cout << "no solution" << endl;
       }
       else if(ans.size()==1)
       {
           cout << "unique: " << ans[0] << endl;
       }
       else
       {
           cout << "ambiguous:" ;

           for(auto x : ans)cout << " " << x;

           cout << endl;
       }
    }
}
