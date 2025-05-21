class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int n = prefix.size();
        for(int i = 0; i < n; i++)
        {
            int left = 0;
            int right = prefix[n-1] - prefix[i];
            if(i == 0)
            {
                left = 0;
            }
            else 
            {
                left = prefix[i-1];
            }
            if(right == left)
            {
                return i;
            }
        }
        return -1;
    }
};