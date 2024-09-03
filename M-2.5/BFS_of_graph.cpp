#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        bool vis[100020];
        memset(vis,false,sizeof(vis));
        vector<int>v;
        queue<int>q;
        q.push(0);
        vis[0] = true;
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            v.push_back(val);
            for(int x:adj[val])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        return v;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
