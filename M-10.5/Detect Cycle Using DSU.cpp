#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int par[10005];
    int group_size[10005];
    void DSU_initialization(int n)
    {
        for(int i=0;i<n;i++) par[i] = -1;
        for(int i=0;i<n;i++) group_size[i] = 1;
    }
    
    int DSU_find(int n)
    {
        if(par[n] == -1) return n;
        int p = DSU_find(par[n]);
        par[n] = p;
        return p;
    }
    
    void DSU_By_Size(int a, int b)
    {
        int pa = DSU_find(a);
        int pb = DSU_find(b);
            if(group_size[pa] > group_size[pb])
            {
                par[pb] = pa;
                group_size[pa]+=group_size[pb];
            }
            else
            {
                par[pa] = pb;
                group_size[pb]+=group_size[pa];
            }
    }	int detectCycle(int V, vector<int>adj[])
	{
	    DSU_initialization(V);
	    for(int i=0;i<V;i++)
        {
            for(int b:adj[i])
            {
                if(i<b)
                {
                    int pa = DSU_find(i);
                    int pb = DSU_find(b);
                    if(pa == pb)return 1;
                    else DSU_By_Size(i,b);
                }
            }
        }
        return 0;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
