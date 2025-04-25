class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        priority_queue<pair<int,int>> heap;
        for(int num: arr)
        {
            int cnt = __builtin_popcount(num);
            heap.push({cnt, num});
        }
        vector<int> ans(heap.size(), 0);
        while(heap.size() > 0)
        {
            ans[heap.size()-1] = heap.top().second;
            heap.pop();
        }
        return ans;
    }
};