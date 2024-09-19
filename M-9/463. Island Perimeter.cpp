class Solution {
public:
    bool vis[105][105];
    int n,m,ans = 0;
    vector<pair<int,int>> v = {{0,1},{1,0},{0,-1},{-1,0}};
    bool valid(int i,int j)
    {
        if(i>=0 && i<n && j>=0 && j<m) return true;
        return false;
    }
    void DFS(int si,int sj, vector<vector<int>>& grid)
    {
        vis[si][sj] = true;
        for(int i=0;i<4;i++)
        {
            int ci = si+v[i].first;
            int cj = sj+v[i].second;
            if(valid(ci,cj))
            {
                if(grid[ci][cj] == 0) ans++;
            }
            else ans++;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                DFS(ci,cj,grid);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1) DFS(i,j,grid);
            }
        }
        return ans;
    }
};