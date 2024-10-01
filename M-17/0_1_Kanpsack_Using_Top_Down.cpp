#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000;
ll dp[N][N];

int knapsack(int n, int weight[], int val[],int w)
{
    if(n<0||w==0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(weight[n]<=w)
    {
        int op1 = knapsack(n-1,weight,val,w-weight[n])+val[n];
        int op2 = knapsack(n-1,weight,val,w);
        return dp[n][w] = max(op1,op2);
    }
    else
    {
        int op = knapsack(n-1,weight,val,w);
        return dp[n][w] = op;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w;
    cin>>n>>w;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j] = -1;
        }
    }
    cout<<knapsack(n-1,a,b,w)<<endl;
    return 0;
}
