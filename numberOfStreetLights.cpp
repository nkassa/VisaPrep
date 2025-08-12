

int findNumberOfPosition(int n, vector<vector<int>>& lights) 
{
    vector<pair<int,int>> interval;
    for(vector<int> light: lights)
    {
        int position = light[0];
        int radius = light[1];
        int start = max(0, position-radius);
        int end = min(n, position+radius);
        interval.push_back({start, end});
    }
    sort(interval.begin(), interval.end());

    int ans = 0;
    int currEnd = 0;
    int i = 0;
    while(currEnd < n)
    {
        int furthest = currEnd;
        while(i < interval.size() && interval[i].first <= currEnd)
        {
            furthest = max(furthest, interval[i].second);
            i++;
        }
        if(currEnd == furthest)
        {
            return -1;
        }

        ans++;
        currEnd = furthest;
    }
    return ans; 
}