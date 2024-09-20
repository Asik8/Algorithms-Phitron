class Solution {
public:
    int n,m;
    bool vis[105][105];
    vector<pair<int,int>> v = {{-1,0},{1,0},{0,-1},{0,1}};
    bool valid(int i, int j)
    {
       if(i>=0 && i<n && j>=0 && j<m) return true;
       else return false; 
    }
    bool f;
    void dfs(int si,int sj,vector<vector<int>>& g)
    {
        vis[si][sj] = true;
        if(si==0 || si==n-1 || sj == 0 || sj==m-1) f = false;
        for(int i=0;i<4;i++)
        {
            int ci = si+v[i].first;
            int cj = sj+v[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && g[ci][cj] == 0) dfs(ci,cj,g);
        }
    }

    int closedIsland(vector<vector<int>>& g) {
        memset(vis,false,sizeof(vis));
        n = g.size();
        m = g[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && g[i][j] == 0)
                {
                    f = true;
                    dfs(i,j,g);
                    if(f) c++;
                }
            }
        }
        return c;
    }
};