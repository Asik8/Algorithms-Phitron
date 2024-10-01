#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w;
    cin>>n>>w;
    int weight[n],val[n];
    for(int i=0;i<n;i++) cin>>weight[i];
    for(int i=0;i<n;i++) cin>>val[i];
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(weight[i-1]<=j)
            {
                int op1 = dp[i-1][j-weight[i-1]]+val[i-1];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1,op2);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}
