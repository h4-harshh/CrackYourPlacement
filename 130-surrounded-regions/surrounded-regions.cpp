class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>&board,int i,int j,vector<vector<int>>&visited)
    {
        visited[i][j]=1;
        int n=board.size();
        int m=board[0].size();

        for(auto &dir:directions)
        {
            int i_=dir[0]+i;
            int j_=j+dir[1];

            if(i_>=0 && i_<n && j_>=0 && j_<m && !visited[i_][j_] && board[i_][j_]=='O')
            {
                dfs(board,i_,j_,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        if(n==0 || m==0) return;

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            //first row
            if(!visited[0][j] && board[0][j]=='O')
            {
                dfs(board,0,j,visited);
            }
            //last row
            if(!visited[n-1][j] && board[n-1][j]=='O')
            {
                dfs(board,n-1,j,visited);
            }
        }
        for(int i=0;i<n;i++)
        {
            //first col
            if(!visited[i][0] && board[i][0]=='O')
            {
                dfs(board,i,0,visited);
            }
            //last col
            if(!visited[i][m-1] && board[i][m-1]=='O')
            {
                dfs(board,i,m-1,visited);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};