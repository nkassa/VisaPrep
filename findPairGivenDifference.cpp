class Solution {
  public:
    bool findPair(vector<int> &arr, int x) 
    {
        // code here
        unordered_set<int> seen;
        for(int num: arr)
        {
            if(seen.find(num+x) != seen.end() || seen.find(num-x) != seen.end())
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};