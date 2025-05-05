class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        priority_queue<pair<int, string>> heap;
        unordered_map<string, int> count;
        for(string word: words)
        {
            count[word]++;
        }
        for(auto [key, val]: count)
        {
            heap.push({-1*val,key});
        }
        vector<string> ans(k);
        while(heap.size() > k)
        {
            heap.pop();
        }
        int i = k-1;
        while(!heap.empty())
        {
            ans[i] = heap.top().second;
            i--;
            heap.pop();
        }
        return ans;
    }
};