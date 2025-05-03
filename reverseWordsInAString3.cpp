class Solution {
public:
    string reverseWords(string s) 
    {
        vector<string> words;
        stringstream ss(s);
        string temp = "";
        while(getline(ss, temp, ' '))
        {
            words.push_back(temp);
        }
        string ans = "";
        for(string str: words)
        {
            int left = 0;
            int right = str.size()-1;
            while(left < right)
            {
                char temp = str[left];
                str[left] = str[right];
                str[right] = temp;
                left++;
                right--;
            }
            ans += str;
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};