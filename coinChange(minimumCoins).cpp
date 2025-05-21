class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) 
    {
        // code here
        vector<int> memo(sum+1, INT_MAX);
        memo[0] = 0;
        for(int i = 1; i <= sum; i++)
        {
            for(int num: coins)
            {
                if(i - num >= 0 && memo[i-num] != INT_MAX)
                {
                    memo[i] = min(memo[i-num] + 1, memo[i]);
                }
            }
        }
        if(memo[sum] == INT_MAX)
        {
            return -1;
        }
        return memo[sum];
    }
};