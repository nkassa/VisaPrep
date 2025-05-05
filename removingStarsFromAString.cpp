class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> stack;
        for(char c: s)
        {
            if(c == '*')
            {
                if(!stack.empty())
                {
                    stack.pop();
                }
            }
            else
            {
                stack.push(c);
            }
        }
        string ans(stack.size(), ' ');
        for(int i = stack.size()-1; i >= 0; i--)
        {
            ans[i] = stack.top();
            stack.pop();
        }
        return ans;
    }
};