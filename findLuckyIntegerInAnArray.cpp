class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int,int> count;
        int ans = -1;
        for(int num : arr)
        {
            count[num]++;
        }
        for(auto [key,val]: count)
        {
            if(key == val)
            {
                ans = max(ans, key);
            }
        }
        return ans;
    }
};