#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz 1005

vector<ll> ar[sz];
bool vis[sz];
ll level[sz]; 
ll parent[sz];

void bfs(ll src)
{
    queue<ll>q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while(!q.empty())
    {
        ll n = q.front();
        q.pop();
        for(ll x:ar[n])
        {
            if(!vis[x]) 
            {
                q.push(x);
                vis[x] = true;
                level[x] = level[n]+1;
                parent[x] = n;
            }
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
        ar[a].pb(b);
        ar[b].pb(a);
    }
    ll src,des;
    cin>>src>>des;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    bfs(src);
    vector <ll> v;
    ll x = des;
    while(x!=-1)
    {
        if(x != -1) v.pb(x);
        x = parent[x];
    }
    reverse(v.begin(),v.end());
    for(ll l:v) cout<<l<<" ";
    return 0;
}