// topic  : Digit Dp
// Everything you do is to maximize your pleasure

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll dp[12][2][99][1003];
ll P10[12];
ll k;
vector<ll>digit;
ll tc = 1;


ll sol1(ll pos,ll is_small,ll digit_sum,ll till_mod)
{
    if(pos >= digit.size())
    {
        if(digit_sum == 0 && till_mod == 0)return 1;
        else return 0;
    }

    if(dp[pos][is_small][digit_sum][till_mod] != -1)return dp[pos][is_small][digit_sum][till_mod];


    ll low = 0, high = digit[pos], val = 0;

    if(is_small)high = 9;

    for(ll i = low ; i <= high ; i++)
    {
        ll sz = (ll)digit.size()-pos-1;

        val += sol1(pos+1,is_small | i<digit[pos],(digit_sum+i)%k,(till_mod + (i*P10[sz])%k)%k);
    }

    return dp[pos][is_small][digit_sum][till_mod] = val;
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
    scanf("%lld",&k);

    if(k<=90)
    {
        get_vector_of_digit(b);
        ans = sol1(0,0,0,0);

        init();
        get_vector_of_digit(a-1);

        ans = ans - sol1(0,0,0,0);
    }
    else ans = 0;
    printf("Case %lld: %lld\n",tc,ans);
    tc++;

}
int main()
{
    ll t;

    for(ll i=0;i<12;i++)
    {
        if(!i)P10[i] = 1;
        else P10[i] = 10*P10[i-1];

    }
    scanf("%lld",&t);

    while(t--)
    {
        init();
        input_and_sol();
    }

    return 0;
}
