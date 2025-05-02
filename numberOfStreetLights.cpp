

int findNumberOfPosition(int n, vector<vector<int>>& lights) 
{
    int ans = 0;
    vector<pair<int,int>> lengthOfRoad;
    for(vector<int> light: lights)
    {
        int position = light[0];
        int radius = light[1];
        lengthOfRoad.push_back({position-radius, position+radius});
    }
    sort(lengthOfRoad.begin(), lengthOfRoad.end());
    vector<pair<int,int>> newRoad;
    for(int i = 0; i < lengthOfRoad.size(); i++)
    {
        if(!newRoad.empty() && newRoad.back().second >= lengthOfRoad[i].first)
        {
            newRoad[newRoad.size()-1] = {newRoad.back().first, max(newRoad.back().second, lengthOfRoad[i].second)};
        }
        else
        {
            newRoad.push_back(lengthOfRoad[i]);
            ans++;
        }
    }
    if(newRoad.size() != 1 || 0 < newRoad[0].first || n > newRoad[0].second)
    {
        return -1;
    }
    return ans;
}