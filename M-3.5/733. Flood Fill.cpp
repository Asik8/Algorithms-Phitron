class Solution {
public:
    int row,col;
    bool vis[50][50];
    vector <pair<int,int>> v = {{-1,0},{1,0},{0,-1},{0,+1}};
    bool valid(int r,int c)
    {
        if(r<0 || r>=row || c<0 || c>=col) return false;
        return true;
    }
    void dfs(int r, int c,int color,vector<vector<int>>& image,int ocol)
    {
        vis[r][c] = true;
        image[r][c] = color;
        for(int i=0;i<4;i++)
        {
            int nr = r+v[i].first;
            int nc = c+v[i].second;
            if(valid(nr,nc) && !vis[nr][nc] && image[nr][nc] == ocol)
            {
                vis[nr][nc] = true;
                dfs(nr,nc,color,image,ocol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            row = image.size();
            col = image[0].size();
            int oldcolor = image[sr][sc];
            if(oldcolor == color) return image;
            memset(vis,false,sizeof(vis));
            dfs(sr,sc,color,image,oldcolor);
            return image;
        }
};