class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> list;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                list.push_back(matrix[row][col]);
            }
        }
        int left = 0;
        int right = list.size()-1;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(list[mid] == target)
            {
                return true;
            }
            if(list[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return false;
    }
};