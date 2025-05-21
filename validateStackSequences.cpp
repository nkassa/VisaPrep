class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int j = 0;
        stack<int> stack;
        for(int i = 0; i < pushed.size(); i++)
        {
            stack.push(pushed[i]);
            while(!stack.empty() && stack.top() == popped[j])
            {
                stack.pop();
                j++;
            }
        }
        return stack.size() == 0;
    }
};