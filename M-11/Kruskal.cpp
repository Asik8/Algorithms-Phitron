#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 1e5+20;
int par[N];
int group_size[N];

void DSU_initialize(int n)
{
    for(int i=0;i<n;i++) 
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}

int find(int n)
{
    if(par[n] == -1) return n;
    int p = find(par[n]);
    par[n] = p;
    return p;
}

void DSU_Union_by_Size(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if(group_size[pa]> group_size[pb])
    {
        par[pb] = pa;
        group_size[pa]+= group_size[pb];
    }
    else
    {
        par[pa] = pb;
        group_size[pb]+= group_size[pa];
    }
}

class Edge
{
    public:
    ll u,v,w;
    Edge(ll u,ll v,ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) 
{
    return a.w<b.w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    DSU_initialize(n);
    vector<Edge>EdgeList;
    while(e--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        EdgeList.pb(Edge(u,v,w));
    }
    sort(EdgeList.begin(),EdgeList.end(),cmp);
    ll total = 0;
    for(Edge edge:EdgeList)
    {
        ll parA = find(edge.u);
        ll parb = find(edge.v);
        if(parA == parb) continue;
        else
        {
            DSU_Union_by_Size(parA,parb);
            total+= edge.w;
        }
    }
    cout<<total<<endl;
    return 0;
}