class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> informTime;
    int maxi = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        this->informTime = informTime;
        for(int i = 0; i < n; i++)
        {
            graph[manager[i]].push_back(i);
        }
        dfs(headID, informTime[headID]);
        return maxi;
    }
    void dfs(int headID, int time)
    {
        maxi = max(time, maxi);
        for(int emp: graph[headID])
        {
            dfs(emp, time + informTime[emp]);
        }
    }
};