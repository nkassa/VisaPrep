class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int left = 0;
        int cnt = 0;
        int ans = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            if(nums[right] == 0)
            {
                cnt++;
            }
            while(cnt > k)
            {
                if(nums[left] == 0)
                {
                    cnt--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};