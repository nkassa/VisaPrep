class Solution {
  public:
    string ans = "";
    string longestPalindrome(string &s) {
        // code here
        for(int i = 0; i < s.size(); i++)
        {
            int even = pali(i, i+1, 0, s);
            int odd = pali(i,i,0);
        }
        return ans;
    }
    void pali(int left, int right, int size, string &s)
    {
        while(left >= 0 && right <= s.size())
    }
};