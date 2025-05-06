class Solution {
public:
    unordered_map<int,string> ans;
    string longestPalindrome(string s) 
    {
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            pali(s,i,i+1);
            pali(s,i,i);
        }
        int maxi = 0;
        for(auto [key,val]: ans)
        {
            maxi = max(maxi, key);
        }
        return ans[maxi];
    }
    void pali(string& s, int left, int right)
    {
        int cnt = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        cnt = right-left-1;
        ans[cnt] = s.substr(left+1, cnt);
    }
};