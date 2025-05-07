class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int m;
    int n;
    vector<vector<int>> mat;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        this->mat = mat;
        queue<vector<int>> queue;
        m = mat.size();
        n = mat[0].size();
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(mat[row][col] == 0)
                {
                    queue.push({row,col, 1});
                }
                else
                {
                    mat[row][col] = INT_MAX;
                }
            }
        }
        while(!queue.empty())
        {
            int row = queue.front()[0];
            int col = queue.front()[1];
            int steps = queue.front()[2];
            queue.pop();
            for(vector<int> direction: directions)
            {
                int nextRow = direction[0] + row;
                int nextCol = direction[1] + col;
                if(valid(nextRow, nextCol) && steps  < mat[nextRow][nextCol])
                {
                    mat[nextRow][nextCol] = steps;
                    queue.push({nextRow, nextCol, steps + 1});
                }
            }
        }
        return mat;
    }
    bool valid(int row, int col)
    {
        return 0 <= row && row < m && 0 <= col && col < n && mat[row][col] != 0;
    }
};