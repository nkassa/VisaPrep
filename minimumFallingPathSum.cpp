class Solution {
public:
    int m;
    int n;
    vector<vector<int>> matrix;
    vector<vector<int>> memo;
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int ans = INT_MAX;
        m = matrix.size();
        n = matrix[0].size();
        this->matrix = matrix;
        memo = vector(m, vector<int>(n, INT_MIN));
        for(int col = 0; col < n; col++)
        {
            memo[0][col] = matrix[0][col];
        }
        for(int col = 0; col < n; col++)
        {
            ans = min( ans, dp(m-1, col));
        }
        return ans;
    }
    int dp(int row, int col)
    {
        if(memo[row][col] != INT_MIN)
        {
            return memo[row][col];
        }
        int sum = 0;
        if(row > 0)
        {
            sum = dp(row-1, col) + matrix[row][col];
        }
        if(row > 0 && col > 0)
        {
            sum = min(sum, dp(row-1, col-1)+ matrix[row][col]);
        }
        if(row > 0 && col < n-1)
        {
            sum = min(sum, dp(row-1, col+1)+ matrix[row][col]);
        }
        memo[row][col] = sum;
        return memo[row][col];
    }
};