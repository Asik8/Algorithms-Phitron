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
    while(e--)
    {
        int l,r;
        cin>>l>>r;
        a[l].pb(r);
    }

    for(vector<int> x:a)
    {
        for(int j=0;j<x.size();j++) cout<<x[j]<<" ";
        cout<<endl;
    }
    return 0;
}