#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 100005;

vector<int> v[N];
bool vis[N];
vector<int> path;
int level[N];
int parent[N];

void bfs_Path_Length(int s,int d)
{
    if(s == d)
    {
        cout<<0<<endl;
        return;
    }
    queue<int>q;
    q.push(s);
    level[s] = 0;
    vis[s] = true;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        for(ll x:v[n])
        {
            if(!vis[x])
            {
                q.push(x);
                level[x] = level[n]+1;
                vis[x] = true;
                parent[x] = n;
            }
        }
    }
    if(parent[d] == -1) 
    {
        cout<<-1<<endl;
        return;
    }
    int l = d;
    while(1)
    {
        if(l == -1) break;
        path.pb(l);
        l = parent[l];
    }
    cout<<path.size()-1<<endl;
    path.clear();
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
        v[a].pb(b);
        v[b].pb(a);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int s,d;
        cin>>s>>d;
        memset(vis,false,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        memset(level,-1,sizeof(level));
        bfs_Path_Length(s,d);
    }
    return 0;
}