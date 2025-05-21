class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        int left = 0;
        int right = (m*n) - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            if(mat[row][col] == x)
            {
                return true;
            }
            else if(mat[row][col] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};