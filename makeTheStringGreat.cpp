class Solution {
public:
    string makeGood(string s) 
    {
        stack<char> stack;
        stack.push(s[0]);
        for(int i = 1; i < s.size(); i++)
        {
            if(stack.size() >= 1 && abs(stack.top()-s[i]) == 32)
            {
                stack.pop();
            }
            else
            {
                stack.push(s[i]);
            }
        }
        int n = stack.size();
        string ans(n, 'x');
        for(int i = stack.size()-1; i >= 0; i--)
        {
            ans[i] = stack.top();
            stack.pop();
        }
        return ans;
    }
};