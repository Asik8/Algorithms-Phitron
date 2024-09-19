class Solution {
public:
    bool vis[200020];
    bool DFS(int s,int d, vector<vector<int>>& adj)
    {
        if(s == d)  return true;
        vis[s] = true;
        for(int x:adj[s])
        {
            if(!vis[x])
            {
                if(DFS(x,d,adj))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        memset(vis,false,sizeof(vis));
        vector<vector<int>> adj(n); 
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return DFS(s, d, adj);
    }
};