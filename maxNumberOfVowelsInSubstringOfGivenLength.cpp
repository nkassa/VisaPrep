class Solution {
public:
    unordered_set<char> seen = {'a', 'e', 'i', 'o', 'u'};
    int maxVowels(string s, int k) 
    {
        int cnt = 0;
        int ans = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++)
        {
            if(seen.find(s[right]) != seen.end())
            {
                cnt++;
            }
            if(right-left+1 > k)
            {
                if(seen.find(s[left]) != seen.end())
                {
                    cnt--;
                }
                left++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};