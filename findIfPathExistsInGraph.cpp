class Solution {
public:
    vector<bool> seen;
    unordered_map<int, vector<int>> graph;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        seen = vector(n, false);
        for(vector<int> edge: edges)
        {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        seen[source] = true;
        return dfs(source, destination);
    }
    bool dfs(int source, int destination)
    {
        if(source == destination)
        {
            return true;
        }
        for(int neighbor: graph[source])
        {
            if(!seen[neighbor])
            {
                seen[neighbor] = true;
                if(dfs(neighbor, destination))
                {
                    return true;
                }
            }
        }
        return false;
    }
};