class Solution {
  public:
    string longestPalindrome(string s) 
    {
        string ans = "";
        // code here
        for(int i = 0; i < s.size(); i++)
        {
            helper(i, i, s, ans);
            helper(i, i + 1, s, ans);
        }
        return ans;
    }
    void helper(int left, int right, string& s, string& ans)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        if(ans.size() < right-left-1)
        {
            ans = s.substr(left+1, right-left-1);
        }
    }
};