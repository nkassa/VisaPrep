class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int left = 1;
        int right = 1;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            left *= nums[i];
            right *= nums[n-1-i];
            ans = max({ans, left, right});
            if(left == 0)
            {
                left = 1;
            }
            if(right == 0)
            {
                right = 1;
            }
        }
        return ans;
    }
};