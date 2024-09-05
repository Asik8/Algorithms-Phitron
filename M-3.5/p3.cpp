#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll N = 1e5+10;
vector<ll> v[N];
bool vis[N];
vector<ll>sz;
ll c=0;

void DFS(ll n,ll src)
{
    c++;
    vis[n] = true;
    for(ll x:v[n])
    {
        if(!vis[x])
        {
            DFS(x,src);
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
    memset(vis,false,sizeof(vis));
    for (int i=0;i<n;i++) 
    {
        c = 0;
        if(!vis[i]) 
        {
            DFS(i,i);
            sz.pb(c);
        }
    }
    sort(sz.begin(),sz.end());
    for (ll x:sz) cout<<x<<" ";
    cout<<endl;
    return 0;
}