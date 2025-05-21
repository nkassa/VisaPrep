class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_set<int> seen;
        int left = 0;
        int ans = 0;
        int curr = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            while(seen.find(nums[right]) != seen.end())
            {
                seen.erase(nums[left]);
                curr -= nums[left];
                left++;
            }
            seen.insert(nums[right]);
            curr += nums[right];
            ans = max(ans, curr);
        }
        return ans;
    }
};