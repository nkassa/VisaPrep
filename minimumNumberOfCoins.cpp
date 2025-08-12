class Solution {
  public:
    vector<int> list = { 2000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    vector<int> minPartition(int N) 
    {
        // code here
        vector<int> ans;
        for(int num: list)
        {
            while(N >= num)
            {
               N -= num;
               ans.push_back(num);
            }
        }
        return ans;
    }
};