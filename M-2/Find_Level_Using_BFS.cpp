#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz 1005

vector<ll> ar[sz];
bool vis[sz];
ll level[sz]; 

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
    ll src;
    cin>>src;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(src);
    for(int i=0;i<n;i++) cout<<i<<" "<<level[i]<<endl;
    return 0;
}