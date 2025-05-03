class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        int end = 0;
        string ans = "";
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == ch)
            {
                end = i;
                break;
            }
        }
        for(int i = end; i >= 0; i--)
        {
            ans += word[i];
        }
        for(int i = end+1; i < word.size(); i++)
        {
            ans += word[i];
        }
        return ans;
    }
};