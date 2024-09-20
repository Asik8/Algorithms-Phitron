class Solution {
public:
    bool vis[505][505];
    int n,m;
    vector<pair<int,int>>v = {{1,0},{0,1},{-1,0},{0,-1}};
    bool valid(int i,int j)
    {
        if(i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }
    bool f;
    void DFS(int si,int sj,vector<vector<int>>& g1, vector<vector<int>>& g2)
    {
        vis[si][sj] = true;
        if(g1[si][sj] == 0) f = false;
        for(int i=0;i<4;i++)
        {
            int ci = si+v[i].first;
            int cj = sj+v[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && g2[ci][cj] == 1) DFS(ci,cj,g1,g2);
        }
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        memset(vis,false,sizeof(vis));
        int ans =0;
        n = g2.size();
        m = g2[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && g2[i][j] == 1)
                {
                    f = true;
                    DFS(i,j,g1,g2);
                    if(f) ans++;
                }
            }
        }
        return ans;
    }
};