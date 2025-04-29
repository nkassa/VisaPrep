class Solution {
public:
    vector<vector<int>> grid;
    int uniquePaths(int m, int n) 
    {
        grid = vector(m, vector<int>(n, -1));
        grid[0][0] = 0;
        return dp(m-1, n-1);
    }
    int dp(int row, int col)
    {
        if(grid[row][col] != -1)
        {
            return grid[row][col];
        }
        int way = 0;
        if(row > 0)
        {
            way += dp(row-1, col);
        }
        if(col > 0)
        {
            way += dp(row, col-1);
        }
        way += 1;
        grid[row][col] = way;
        return grid[row][col];
    }
};