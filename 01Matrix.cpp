class Solution {
public:
    int m;
    int n;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<pair<int,int>> queue;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(mat[row][col] == 0)
                {
                    queue.push({row,col});
                }
                else
                {
                    mat[row][col] = INT_MAX;
                }
            }
        }
        while(!queue.empty())
        {
            int row = queue.front().first;
            int col = queue.front().second;
            queue.pop();
            for(vector<int> direction: directions)
            {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];
                if(valid(nextRow, nextCol) && mat[nextRow][nextCol] > mat[row][col] + 1)
                {
                    mat[nextRow][nextCol] = mat[row][col] + 1;
                    queue.push({nextRow,nextCol});
                }
            }
        }
        return mat;
    }
    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};