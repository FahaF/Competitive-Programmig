// topic  : Digit Dp
// It is okay


// This question was not clear enough or I am dumb Just

// In the question  you are asked to count the numbers if  ((sum of digits of even index) - (sum of digits of odd index)) = 1
// another thins is that the indexing of digits is from right and 1 indexed.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll dp1[12][2][2][99][99][2];


vector<ll>digit;
ll tc = 1;

ll sol1(ll pos,ll is_small,ll is_start,ll ev,ll od,ll eta)
{
    if(pos == digit.size())
    {
        if(!eta && (ev-od) == 1)return 1;
        else if(eta && (od-ev) == 1)return 1;
        else return 0;
    }

    if(dp1[pos][is_small][is_start][ev][od][eta] != -1)return dp1[pos][is_small][is_start][ev][od][eta];

    ll low = 0,high = digit[pos];

    if(is_small)high = 9;

    ll val = 0;

    for(ll i = low; i <= high; i++)
    {
        if(is_start||i>0)
        {
            if(eta)
            val += sol1(pos+1,is_small|i<digit[pos],1,ev,od+i,0);
            else
            val += sol1(pos+1,is_small|i<digit[pos],1,ev+i,od,1);
        }
        else val += sol1(pos+1,is_small|i<digit[pos],0,ev,od,eta);

    }

    return dp1[pos][is_small][is_start][ev][od][eta] = val;

}

void init()
{
    memset(dp1,-1,sizeof dp1);
    digit.clear();
}
void get_vector_of_digit(ll x)
{
    while(x)
    {
        digit.push_back(x%10);
        x/=10;
    }
    reverse(digit.begin(),digit.end());
}
void input_and_sol()
{


    ll a,b,ans;

    scanf("%lld",&a);
    scanf("%lld",&b);
    get_vector_of_digit(b);
    ans = sol1(0,0,0,0,0,1);
    a--;
    if(a>0)
    {
        init();
        get_vector_of_digit(a);
        ans = ans - sol1(0,0,0,0,0,1);
    }

    printf("%lld\n",ans);
    tc++;

}

int main()
{
    ll t;

    scanf("%lld",&t);

    while(t--)
    {
        init();
        input_and_sol();
    }

    return 0;
}


