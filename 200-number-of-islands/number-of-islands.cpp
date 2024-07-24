class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<char>>&grid,int i,int j,int n,int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=-1;

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            //it.first=i
            //it.second=j

            for(auto &dir:directions)
            {
                int i_=it.first+dir[0];
                int j_=it.second+dir[1];

                if(i_<0 || i_>=n || j_<0 || j_>=m || grid[i_][j_]!='1')
                {
                    continue;
                }
                else{
                    q.push({i_,j_});
                    grid[i_][j_]='$';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};