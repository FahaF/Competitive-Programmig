// topic  : Digit Dp
// Everything you do is to maximize your pleasure

#include<bits/stdc++.h>
using namespace std;
#define int long long


int dp1[12][2][2];
int dp2[12][2];

vector<int>digit;
int tc = 1;

int sol2(int pos,int is_small)
{
    if(pos >= digit.size())return 1;

    if(dp2[pos][is_small] != -1)return dp2[pos][is_small];

    int low = 0,high = digit[pos];
    if(is_small)high = 9;

    int val = 0;

    for(int i = low; i <= high; i++)
    {
        val += sol2(pos+1, is_small | i<digit[pos]);
    }

    return dp2[pos][is_small] = val;
}

int sol1(int pos,int is_small,int is_start)
{
    if(pos >= digit.size())return 0;

    if(dp1[pos][is_small][is_start] != -1)return dp1[pos][is_small][is_start];

    int low = 0,high = digit[pos];

    if(is_small)high = 9;

    int val = 0;

    for(int i = low; i <= high; i++)
    {
        val += sol1(pos+1, is_small | i<digit[pos], is_start|(i!=0));

        if(is_start && i==0)
        {
            val += sol2(pos+1,is_small|i<digit[pos]);
        }
    }

    return dp1[pos][is_small][is_start] = val;

}

void init()
{
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    digit.clear();
}
void get_vector_of_digit(int x)
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


    int a,b;

    scanf("%lld",&a);
    scanf("%lld",&b);

    get_vector_of_digit(b);

    int ans = sol1(0,0,0);

    if(a)
    {
        init();
        get_vector_of_digit(a-1);
        ans = ans - sol1(0,0,0);
    }
    else ans++;

    printf("Case %lld: %lld\n",tc,ans);
    tc++;

}
main()
{
    int t;

    scanf("%lld",&t);

    while(t--)
    {
        init();
        input_and_sol();
    }
}
