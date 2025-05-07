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
                int left = 0;
                int right = temp.size()-1;
                while(left < right)
                {
                    char t = temp[left];
                    temp[left] = temp[right];
                    temp[right] = t;
                    left++;
                    right--;
                }
                ans += temp;
                ans += " ";
                temp = "";
            }
        }
        ans.pop_back();
        return ans;
    }
};
