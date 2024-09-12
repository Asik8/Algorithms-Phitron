#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll N = 1e5+10;
#define mx 30000

class Edge
{
   public:
   int u;
   int v;
   int c;
   Edge(int u,int v,int c)
   {
    this->u = u;
    this->v = v;
    this->c = c;
   }  
};

int dis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<Edge> edgeList;
    while(e--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        edgeList.pb(Edge(u,v,c));
    }
    for(int i=1;i<=n;i++) dis[i] = mx;
    dis[1] = 0;
    for(int i=0;i<n-1;i++)
    {
        for(Edge x:edgeList)
        {
            if(dis[x.u] < mx && dis[x.u]+x.c < dis[x.v]) dis[x.v] =  dis[x.u]+x.c;
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}