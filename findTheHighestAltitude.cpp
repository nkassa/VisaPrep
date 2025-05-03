class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int alt = 0;
        int ans = 0;
        for(int num: gain)
        {
            alt += num;
            ans = max(ans, alt);
        }
        return ans;
    }
};