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
        int i,j,k,l,m,n,cnt = 0,sum;

        bool ok = true;

        cin >> n >> k;

        int ar[n+2];

        for(i=1;i<=n;i++)
        {
            cin >> ar[i];

            if(ar[i] > k)ok = false;
        }

        if(!ok){cout<<"-1"<<endl;continue;}

        for(i=1;i<=n;)
        {
            sum = 0;
            while(sum+ar[i] <= k && i<=n)sum+=ar[i],i++;

            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
