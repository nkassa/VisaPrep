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
            int sum = carry;
            if(i >= 0)
            {
                sum += a[i] - '0';
            }
            if(j >= 0)
            {
                sum += b[j] - '0';
            }
            ans += '0' + (sum % 2);
            carry = sum / 2;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};