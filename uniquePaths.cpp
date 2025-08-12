class Solution {
public:
    vector<vector<int>> memo;
    int m;
    int n;
    int uniquePaths(int m, int n) 
    {
        this->m = m;
        this->n = n;
        memo = vector(m, vector<int>(n, -1));
        memo[0][0] = 1;
        return dp(m-1, n-1);
    }
    int dp(int row, int col)
    {
        if(memo[row][col] != -1)
        {
            return memo[row][col];
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
        memo[row][col] = way;
        return memo[row][col];
    }
};