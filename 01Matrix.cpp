class Solution {
public:
    int m;
    int n;
    vector<vector<int>> mat;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        this->mat = mat;
        m = mat.size();
        n = mat[0].size();
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(mat[row][col] == 1)
                {
                    seen = vector(m, vector<bool>(n, false));
                    seen[row][col] = true;
                    mat[row][col] = dfs(row, col, 0);
                }
            }
        }
        return mat;
    }
    int dfs(int row, int col, int cnt)
    {
        int ans = 0;
        if(mat[row][col] == 0)
        {
            return cnt;
        }
        for(vector<int> direction: directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                ans = dfs(nextRow, nextCol, cnt + 1);
            }
        }
        return ans;
    }
    int valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};