class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) 
    {
        // code here
        unordered_set<int> seen;
        for(int num: arr)
        {
            if(x == 0 && num == 0)
            {
                return true;
            }
            if(num == 0)
            {
                continue;
            }
            int i = x % num;
            int val = x / num;
            if(i == 0 && seen.find(val) != seen.end())
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};