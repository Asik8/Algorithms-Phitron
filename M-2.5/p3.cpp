#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll N = 1e5+5;
vector<ll>v[N];

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
    ll l;
    cin>>l;
    cout<<v[l].size()<<endl;
    return 0;
}