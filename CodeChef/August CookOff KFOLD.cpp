/*
Offline practice
Topic : Implementation

*/



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int tst;


    cin >> tst;

    while(tst--)
    {
        ll i,j,k,l,m,n,p,cnt=0;

        cin >> n >> k;

        p = n/k;

        string s;

        cin >> s;

        for(i=0;i<n;i++)cnt += (s[i]-'0');

        if(cnt%p || (n-cnt)%p)cout << "IMPOSSIBLE" << endl;
        else
        {
            m = cnt/p;

            l = k-m;

            string tmp = "",rtmp;

            while(l>0)tmp+="0",l--;

            while(m>0)tmp+="1",m--;

            rtmp = tmp;

            reverse(rtmp.begin(),rtmp.end());

            for(i=0;i<p;i++)
            {
                if(i%2==0)cout<<tmp;
                else cout<<rtmp;
            }

            cout<<endl;
        }


    }

    return 0;
}


