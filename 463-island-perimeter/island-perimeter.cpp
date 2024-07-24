class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,int &peri,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
        {
            peri++;
            return;
        }
        if(grid[i][j]==-1)
        {
            return;
        }
        grid[i][j]=-1;

        dfs(grid,i-1,j,peri,n,m);
        dfs(grid,i+1,j,peri,n,m);
        dfs(grid,i,j-1,peri,n,m);
        dfs(grid,i,j+1,peri,n,m);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int peri=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,peri,n,m);
                    return peri;
                }
            }
        }
        return peri;
    }
};