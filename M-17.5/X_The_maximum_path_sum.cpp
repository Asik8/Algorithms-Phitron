#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[11][11];
ll max_Sum(ll i,ll j)
{
    if(i>=n || j>=m) return -1000000;
    if(i==n-1 && j==m-1) return a[i][j];
    ll down = max_Sum(i+1,j);
    ll right = max_Sum(i,j+1);
    return a[i][j] + max(down,right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<max_Sum(0,0)<<endl;
    return 0;
}