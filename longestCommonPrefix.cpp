class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = strs[0];
        for(string str: strs)
        {
            while(prefix.size() > 0 && str.find(prefix) != 0)
            {
                prefix.pop_back();
            }
            if(prefix.size() == 0)
            {
                return "";
            }
        }
        return prefix;
    }
};