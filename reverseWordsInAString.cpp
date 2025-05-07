class Solution {
public:
    string reverseWords(string s) 
    {
        string temp = "";
        string ans = "";
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                temp += s[i];
            }
            if(temp.size() != 0 && (s[i] == ' ' || i == 0))
            {
                string ordered = "";
                for(int j = temp.size()-1; j >= 0; j--)
                {
                    ordered += temp[j];
                }
                ans += ordered;
                ans += " ";
                temp = "";
            }
        }
        ans.pop_back();
        return ans;
    }
};