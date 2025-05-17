class Solution {
  public:
    string longestPalindrome(string s) 
    {
        string ans = "";
        int size = 0;
        // code here
        for(int i = 0; i < s.size(); i++)
        {
            helper(i, i, s);
            helper(i, i + 1, s);
        }
        return ans;
    }
    void helper(int left, int right, string& s)
    {
        int cnt = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left++;
            right--;
            cnt++;
        }
        if(size < cnt)
        {
            size = cnt;
            ans = s.sbstr(left, right-left);
        }
    }
};