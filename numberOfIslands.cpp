class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    int m;
    int n;
    vector<vector<char>> grid;
    vector<vector<bool>> seen;
    int numIslands(vector<vector<char>>& grid) 
    {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n, false));
        int numOfIs = 0;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(!seen[row][col] && grid[row][col] == '1')
                {
                    numOfIs++;
                    seen[row][col] = true;
                    dfs(row, col);
                }
            }
        }
        return numOfIs;
    }
    void dfs(int row, int col)
    {
        for(vector<int> direction: directions)
        {
            int nextRow = direction[0] + row;
            int nextCol = direction[1] + col;
            if(valid(nextRow,nextCol) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                dfs(nextRow, nextCol);
            }
        }
    }
    bool valid(int row, int col)
    {
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == '1';
    }
};