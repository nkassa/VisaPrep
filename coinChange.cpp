class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = amount+1;
        vector<int> memo(n,n);
        memo[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] >= 0)
                {
                    memo[i] = min(memo[i], 1 + memo[i-coins[j]]);
                }
            }
        }
        if(memo[amount] != n)
        {
            return memo[amount];
        }
        return -1;
    }
};////