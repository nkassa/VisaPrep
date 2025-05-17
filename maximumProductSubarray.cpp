class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int sum = 1;
        int ans = INT_MIN;
        for(int num: nums)
        {
            sum *= num;
            ans = max(ans, sum);
            if(sum <= 0)
            {
                sum = 1;
            }
        }
        return ans;
    }
};