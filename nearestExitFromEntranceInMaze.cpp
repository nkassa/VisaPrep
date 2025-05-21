class Solution {
public:
    vector<vector<char>> maze;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> seen;
    int m;
    int n;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        m = maze.size();
        n = maze[0].size();
        this->maze = maze;
        seen = vector(m, vector<bool>(n, false));
        if(maze[entrance[0]][entrance[1]] == '+')
        {
            return -1;
        }

        queue<vector<int>> queue;
        queue.push({entrance[0], entrance[1], 0});
        seen[entrance[0]][entrance[1]] = true;
        while(!queue.empty())
        {
            int row = queue.front()[0];
            int col = queue.front()[1];
            int step = queue.front()[2];
            queue.pop();
            if(row == 0 || row == m-1 || col == 0 || col == n-1)
            {
                if(row != entrance[0] || col != entrance[1])
                {
                    return step;
                }
            }
            for(vector<int> direction: directions)
            {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];
                if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
                {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, step + 1});
                }
            }
        }
        return -1;
    }
    bool valid(int row, int col)
    {
        return 0 <= row && row < m && 0 <= col && col < n && maze[row][col] == '.';
    }
};