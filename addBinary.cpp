class Solution {
public:
    string addBinary(string a, string b) 
    {
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        string ans = "";
        while(i >= 0 || j >= 0 || carry)
        {
            int x = 0;
            int y = 0;
            if(j < 0)
            {
                y = 0;
            }
            else
            {
                y = b[j] - '0';
            }
            if(i < 0)
            {
                x = 0;
            }
            else
            {
                x = a[i] - '0';
            }
            if(x+y+carry == 2)
            {
                carry = 1;
                ans += '0';
            }
            else if(x+y+carry == 0)
            {
                carry = 0;
                ans += '0';
            }
            else if(x+y+carry == 1)
            {
                carry = 0;
                ans += '1';
            }
            else if(x+y+carry == 3)
            {
                carry = 1;
                ans += '1';
            }
            j--;
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};