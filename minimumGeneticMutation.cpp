class Solution {
public:
    unordered_set<string> allowed;
    unordered_set<string> seen;
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        for(string s: bank)
        {
            allowed.insert(s);
        }
        queue<pair<string,int>> queue;
        queue.push({startGene, 0});
        seen.insert(startGene);
        string choice = "ACGT";
        while(!queue.empty())
        {
            string curr = queue.front().first;
            int steps = queue.front().second;
            queue.pop();
            if(curr == endGene)
            {
                return steps;
            }
            for(char c: choice)
            {
                for(int i = 0; i < curr.size(); i++)
                {
                    string neighbor = curr;
                    neighbor[i] = c;
                    if(seen.find(neighbor) == seen.end() && allowed.find(neighbor) != allowed.end())
                    {
                        queue.push({neighbor, steps + 1});
                        seen.insert(neighbor);
                    }
                }
            }
        }
        return -1;
    }
};