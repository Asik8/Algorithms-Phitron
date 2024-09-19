class Solution {
public:
    bool vis[305][305];
    int n,m,c=0;
    vector<pair<int, int>> v = {{0,1},{0,-1},{1,0},{-1,0}};
    bool valid(int i,int j)
    {
        if(i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }
    void DFS(int si, int sj, vector<vector<char>>& grid)
    {
        vis[si][sj] = true;
        for(int i=0;i<4;i++)
        {
            int ci = si+v[i].first;
            int cj = sj+v[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '1') DFS(ci,cj,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        memset(vis,false,sizeof(vis));
        c=0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    DFS(i,j,grid);
                    c++;
                }
            }
        }
        return c;
    }
};