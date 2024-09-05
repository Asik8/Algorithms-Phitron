#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll N = 1e5+10;
vector<ll> v[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    while(e--)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for (int i=0;i<n;i++)
    {
        
    }       
    return 0;
}