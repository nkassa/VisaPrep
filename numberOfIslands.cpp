class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    int m;
    int n;
    vector<vector<bool>> seen;
    vector<vector<char>> grid;
    int numIslands(vector<vector<char>>& grid) 
    {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        seen = vector(m, vector<bool>(n, false));
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
               if(grid[row][col] == '1' && seen[row][col] == false)
               {
                    ans++;
                    seen[row][col] = true;
                    dfs(row, col);
               } 
            }
        }
        return ans;
    }
    void dfs(int row, int col)
    {
        for(vector<int> direction: directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(valid(nextRow, nextCol) && seen[nextRow][nextCol] == false)
            {
                seen[nextRow][nextCol] = true;
                dfs(nextRow, nextCol);
            }
        }
    }
    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1';
    }
};