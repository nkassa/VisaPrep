class Solution {
public:
    int size = 0;
    unordered_map<int,int> count;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        size = nums.size();

        for(auto num: nums)
        {
            count[num] += 1;
        }

        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, curr);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int> curr)
    {
        if(curr.size() == size)
        {
            ans.push_back(curr);
            return;
        }
        for(auto [key, val]: count)
        {
            if(val > 0)
            {
                curr.push_back(key);
                count[key] --;
                backtrack(ans, curr);
                curr.pop_back();
                count[key] ++;
            }
        }
    }
};