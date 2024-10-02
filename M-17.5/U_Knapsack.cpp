#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dp[105][105];

ll mval(ll n,ll a[],ll b[],ll w)
{
    if(n<0 || w==0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(w>= a[n]) 
    {
        int op1 = mval(n-1,a,b,w-a[n])+b[n];
        int op2 = mval(n-1,a,b,w);
        return dp[n][w] = max(op1,op2);
    }
    else return dp[n][w] = mval(n-1,a,b,w);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,w;
    cin>>n>>w;
    ll a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    memset(dp,-1,sizeof(dp));
    cout<<mval(n-1,a,b,w)<<endl;
    return 0;
}