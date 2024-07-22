class Solution {
public:
    void transpose(vector<vector<int>>& matrix,int n,int m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    void reverse_columns(vector<vector<int>>& matrix,int n,int m)
    {
        for(int i=0;i<n;i++)
        {
            int low=0;

            while(low<m/2)
            {
                swap(matrix[i][low],matrix[i][m-1-low]);
                low++;
            }
            // for(int j=0;j<m/2;j++)
            // {
            //     swap(matrix[i][j],matrix[i][m-1-j]);
            // }
        }
    }


    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        transpose(matrix,n,m);
        reverse_columns(matrix,n,m);
    }
};