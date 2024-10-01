#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll N = 1e6+20;
ll dp[N];

ll Fibo(ll n)
{
    if(n==0 || n==1) return n;
    if(dp[n] != -1) return dp[n];
    ll a = Fibo(n-1)+Fibo(n-2);
    dp[n] = a;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<Fibo(n)<<endl;
    return 0;
}