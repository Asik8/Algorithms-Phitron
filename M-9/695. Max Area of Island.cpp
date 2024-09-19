class Solution {
public:
    bool vis[55][55];
    int n,m,ans = INT_MIN,c=0;
    vector<pair<int,int>> v = {{0,1},{1,0},{0,-1},{-1,0}};
    bool valid(int i,int j)
    {
        if(i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }
    void DFS(int si,int sj,vector<vector<int>>& grid)
    {
        vis[si][sj] = true;
        c++;
        for(int i=0;i<4;i++)
        {
            int ci = si+v[i].first;
            int cj = sj+v[i].second;
            {
                if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == 1)
                {
                    DFS(ci,cj,grid);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        ans= 0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    c = 0;
                    DFS(i,j,grid);
                    if(c>ans) ans = c;
                }
            }
        }
        return ans;
    }
};