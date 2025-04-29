class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int> count;
        for(char c: magazine)
        {
            count[c]++;
        }
        for(char c: ransomNote)
        {
            if(count.find(c) == count.end())
            {
                return false;
            }
            count[c]--;
            if(count[c] == 0)
            {
                count.erase(c);
            }
        }
        return true;
    }
};