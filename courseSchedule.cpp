class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(vector<int> req: prerequisites)
        {
            adj[req[1]].push_back(req[0]);
            indegree[req[0]]++;
        }
        queue<int> queue;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }
        int cnt = 0;
        while(!queue.empty())
        {
            cnt++;
            int pre = queue.front();
            queue.pop();
            for(int course: adj[pre])
            {
                indegree[course]--;
                if(indegree[course] == 0)
                {
                    queue.push(course);
                }
            }
        }
        return cnt == numCourses;
    }
};