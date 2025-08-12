class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(int num: arr)
        {
            int cnt = 0;
            int val = num;
            while(num > 0)
            {
                cnt += 1;
                num = num & (num-1);
            }
            heap.push({cnt, val});
        }
        vector<int> ans;
        while(!heap.empty())
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};