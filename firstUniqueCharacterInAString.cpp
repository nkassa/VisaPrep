class Solution {
public:
    int firstUniqChar(string s) 
    {
        int n = s.size();
        unordered_map<char,int> count;
        for(int i = 0; i < n; i++)
        {
            count[s[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(count[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};