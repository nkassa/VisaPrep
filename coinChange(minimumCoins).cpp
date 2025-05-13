class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) 
    {
        // code here
        int ans = INT_MAX;
        backtracking(ans, 0, coins, sum, 0);
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
    void backtracking(int& ans, int Coins, vector<int>& coins, int sum, int idx)
    {
        if(0 > sum)
        {
            return;
        }
        if(sum == 0)
        {
            ans = min(ans, Coins);
        }
        for(int i = idx; i < coins.size(); i++)
        {
            sum -= coins[i];
            backtracking(ans, Coins+1, coins, sum, i);
            sum += coins[i];
        }
    }
};