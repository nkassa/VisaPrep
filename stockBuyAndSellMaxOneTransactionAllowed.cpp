class Solution {
  public:
    int maximumProfit(vector<int> &prices) 
    {
        // code here
        int num = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            num = min(num, prices[i]);
            ans = max(ans, prices[i] - num);
        }
        return ans;
    }
};