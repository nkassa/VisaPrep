class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> count;
        for(int i = 0; i < nums.size(); i++)
        {
            int left = target - nums[i];
            if(count.find(left) != count.end())
            {
                return {count[left], i};
            }
            count[nums[i]] = i;
        }
        return {};
    }
};