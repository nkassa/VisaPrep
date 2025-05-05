class Solution {
public:
    string simplifyPath(string path) 
    {
        stringstream ss(path);
        string temp = "";
        vector<string> list;
        while(getline(ss, temp, '/'))
        {
            if(temp.size() == 0 || temp == ".")
            {
                continue;
            }
            else if(temp == "..")
            {
                if(list.size() > 0)
                {
                    list.pop_back();
                }
            }
            else 
            {
                list.push_back(temp);
            }
        }
        string ans = "";
        for(int i = 0; i < list.size(); i++)
        {
            ans += '/';
            ans += list[i];
        }
        if(ans == "")
        {
            return "/";
        }
        return ans;
    }
};