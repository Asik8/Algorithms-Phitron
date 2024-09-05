#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll N = 1e5+5;
vector<ll>v[N];
bool vis[N];
ll c=0;

void No_Of_Visit_DFS(ll n)
{
    vis[n] = true;
    for(ll x:v[n])
    {
        if(!vis[x])
        {
            c++;
            No_Of_Visit_DFS(x);
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
    ll l;
    cin>>l;
    memset(vis,false,sizeof(vis));
    No_Of_Visit_DFS(l);
    cout<<c+1<<endl;
    return 0;
}