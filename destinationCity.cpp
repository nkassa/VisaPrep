class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string,int> count;
        for(vector<string> path: paths)
        {
            count[path[0]] += 1;
            count[path[1]] += 0;
        }
        for(auto [key,value]: count)
        {
            if(value == 0)
            {
                return key;
            }
        }
        return "";
    }
};