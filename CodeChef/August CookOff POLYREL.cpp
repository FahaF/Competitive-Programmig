/*
Offline practice
Topic : Greedy

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
        ll i,j,k,l,m,n,cnt = 0,x,y;

        cin >> n ;

        for(i=0;i<n;i++)cin >> x >> y;


        while(n>=3)
        {
            cnt += n;
            n /= 2;
        }

        cout << cnt << endl;
    }

    return 0;
}

