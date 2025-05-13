class Solution {
  public:
    string ans = "";
    string longestPalindrome(string &s) {
        // code here
        for(int i = 0; i < s.size(); i++)
        {
            pali(i, i+1, s);
            pali(i,i,s);
        }
        return ans;
    }
    void pali(int left, int right, string &s)
    {
        while(left >= 0 && right <= s.size()-1 && s[left]==s[right])
        {
            left--;
            right++;
        }
        int size = (right-1) - (left+1) + 1;
        if(ans.size() < size)
        {
            ans = s.substr(left+1, size);
        }
    }
};