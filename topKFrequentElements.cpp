class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ans;
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        priority_queue<pair<int,int>> heap;
        for(auto [key, val]: count)
        {
            heap.push({val, key});
        }
        while(k > 0)
        {
            int front = heap.top().second;
            heap.pop();
            ans.push_back(front);
            k--;
        }
        return ans;
    }
};
