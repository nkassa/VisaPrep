class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        priority_queue<pair<int,int>> heap;
        for(int num: arr)
        {
            int cnt = 0;
            int val = num;
            while(num > 0)
            {
                cnt++;
                num &= (num-1);
            }
            heap.push({cnt, val});
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