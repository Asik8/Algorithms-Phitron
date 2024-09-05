#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll N = 1e5+10;
vector<ll> v[N];
bool vis[N];

void DFS(ll n)
{
    vis[n] = true;
    for(ll x:v[n])
    {
        if(!vis[x])
        {
            DFS(x);
        }
    }
}

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
    ll c=0;
    for (int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            c++;
            DFS(i);
        }
    }   
    cout<<c<<endl;    
    return 0;
}