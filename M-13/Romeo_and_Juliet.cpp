#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
const int N = 200005;
vector<vector<int>>Edges(N);
bool vis[N];
int dis[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int c:Edges[par])
        {
            if(!vis[c])
            {
                vis[c] = true;
                dis[c] = dis[par]+1;
                q.push(c);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        Edges[a].pb(b);
        Edges[b].pb(a);
    }
    int x,d,k;
    cin>>x>>d>>k;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    bfs(x);
    if(dis[d] != -1 && dis[d]<=k*2) py
    else pn
    return 0;
}