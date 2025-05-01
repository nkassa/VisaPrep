

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
        if(!newRoad.empty() && lengthOfRoad[i].second < newRoad.back().second)
        {
            newRoad[newRoad.size()-1] = {newRoad.back().first, newRoad.back().second};
        }
        else if(!newRoad.empty() && newRoad.back().second > lengthOfRoad[i].first)
        {
            newRoad[newRoad.size()-1] = {newRoad.back().first, lengthOfRoad[i].second};
            ans++;
        }
        else
        {
            newRoad.push_back(lengthOfRoad[i]);
        }
    }
    if(newRoad.size() != 1)
    {
        return -1;
    }
    return 0 >= newRoad[0][0] && n <= newRoad[0][1];
}