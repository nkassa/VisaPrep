class Solution {
  public:
    int ans = 0;
    string longestPalindrome(string s) 
    {
        // code here
        for(int i = 0; i < s.size(); i++)
        {
            helper(i, i, s);
            helper(i, i + 1, s);
        }
        return ans;
    }
    void helper(int left, int right, string& s)
};