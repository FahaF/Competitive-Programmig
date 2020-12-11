// topic  : Digit Dp
// Everything you do is to maximize your pleasure

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll dp[12][2][99];
vector<ll>digit;
ll tc = 1;
set<ll>st;

ll sol1(ll pos,ll is_small,ll digit_sum)
{
    if(pos >= digit.size())
    {

        if(st.count(digit_sum))return 1;
        else return 0;
    }

    if(dp[pos][is_small][digit_sum] != -1)return dp[pos][is_small][digit_sum];


    ll low = 0, high = digit[pos], val = 0;

    if(is_small)high = 9;

    for(ll i = low ; i <= high ; i++)
    {

        val += sol1(pos+1,is_small | i<digit[pos],digit_sum+i);
    }

    return dp[pos][is_small][digit_sum] = val;
}
void init()
{
    memset(dp,-1,sizeof dp);
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
    ans = sol1(0,0,0);
    if(a)
    {
        init();
        get_vector_of_digit(a-1);
        ans = ans - sol1(0,0,0);
    }

    printf("%lld\n",ans);
    tc++;

}
bool prime(ll x)
{
    for(ll i=3; i*i<=x; i++)if(x%i==0)return  false;
    return true;
}
int main()
{
    st.insert(2);
    for(ll i=3; i<=100; i+=2)
    {
        if(prime(i))st.insert(i);
    }
    ll t;

    scanf("%lld",&t);

    while(t--)
    {
        init();
        input_and_sol();
    }

    return 0;
}

