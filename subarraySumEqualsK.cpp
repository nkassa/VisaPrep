class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int left = 0;
        int ans = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while(sum >= k && left <= right)
            {
                if(sum == k)
                {
                    ans++;
                }
                sum -= nums[left];
                left++;
            }
        }
        return ans;
    }
};