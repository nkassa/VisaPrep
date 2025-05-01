int findNumberOfPosition(vector<vector<int>>& lights) 
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
    for(int i = 1; i < lengthOfRoad.size(); i++)
    {
        if(lengthOfRoad[i][1] < lengthOfRoad[i-1][1])
        {
            lengthOfRoad[i] = {lengthOfRoad[i-1][0], lengthOfRoad[i-1][1]};
        }
        else if(lengthOfRoad[i-1][1] > lengthOfRoad[i][0])
        {
            lengthOfRoad[i] = {lengthOfRoad[i-1][0], lengthOfRoad[i][1]};
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
    return ans;
    
}