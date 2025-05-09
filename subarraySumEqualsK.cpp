class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> seen;
        seen[0] = 1;
        for(int num: nums)
        {
            sum += num;
            int diff = sum - k;
            if(seen.find(diff) != seen.end())
            {
                ans += seen[diff];
            }
            seen[sum]++;
        }
        return ans;
    }
};

