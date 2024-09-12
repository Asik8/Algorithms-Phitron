#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 101

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll a[mx][mx];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == -1) a[i][j] = INT_MAX;
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][k] != INT_MAX && a[k][j] != INT_MAX)
                    a[i][j] = min(a[i][k]+a[k][j],a[i][j]);
            }
        }
    }
    ll mn = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]>mn && a[i][j] != INT_MAX) mn = a[i][j];
        }
    }
    cout<<mn<<endl;
}
