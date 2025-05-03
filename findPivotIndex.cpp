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
            if(i == 0)
            {
                int left = 0;
                int right = prefix[n-1] - prefix[i];
                if( right == left)
                {
                    return i;
                }
            }
            else if(i == n-1)
            {
                int left = prefix[i-1];
                int right = 0;
                if( right == left)
                {
                    return i;
                }
            }
            else
            {
                int left = prefix[i-1];
                int right = prefix[n-1] - prefix[i];
                if(right == left)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};