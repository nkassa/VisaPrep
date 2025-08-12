class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        dp(0, 0, "", ans, n);
        return ans;
    }
    void dp(int open, int closed, string curr, vector<string>& ans, int& n)
    {
        if(open == closed && open + closed == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open < n)
        {
            dp(open + 1, closed, curr + '(', ans, n);
        }
        if(closed < open)
        {
            dp(open, closed + 1, curr + ')', ans, n);
        }
    }
};