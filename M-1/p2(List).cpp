#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<int> a[n];
    memset(a,0,sizeof(a));
    while(e--)
    {
        int l,r;
        cin>>l>>r;
        a[l][r] = 1;
        a[r][l] = 1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}