#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll N = 100005;
vector<ll>v[N];
bool vis[N];
ll level[N];
ll Parent[N];

void BFS_Level(int r)
{
    queue<ll>q;
    q.push(r);
    vis[r] = true;
    level[r] = 0;
    while(!q.empty())
    {
        ll n = q.front();
        q.pop();
        for(ll x:v[n])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x] = true;
                Parent[x] = n;
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
        v[a].pb(b);
        v[b].pb(a);
    }
    int l;
    cin>>l;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(Parent,-1,sizeof(Parent));
    BFS_Level(0);
    vector<ll>a;
    for(ll i=0;i<n;i++)
        if(level[i] == l) a.pb(i);
    sort(a.begin(),a.end(),greater<ll>());
    for(ll x:a)cout<<x<<" ";
    cout<<endl;
    return 0;
}