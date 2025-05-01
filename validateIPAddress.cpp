class Solution {
public:
    string validIPAddress(string queryIP) 
    {
        if(queryIP[queryIP.size()-1] == '.' || queryIP[queryIP.size()-1] == ':')
        {
            return "Neither";
        }
        vector<string> IP4;
        string temp = "";
        stringstream ss(queryIP);
        while(getline(ss, temp, '.'))
        {
            IP4.push_back(temp);
        }
        vector<string> IP6;
        temp = "";
        stringstream s(queryIP);
        while(getline(s, temp, ':'))
        {
            IP6.push_back(temp);
        }
        cout << IP6.size() << endl;
        if(IP4.size() == 4)
        {
            return ipv4(IP4);
        }
        else if(IP6.size() == 8)
        {
            return ipv6(IP6);
        }
        return "Neither";
    }
    string ipv4(vector<string> IP4)
    {
        for(string sec: IP4)
        {
            if(sec.size() == 0 || sec.size() > 1 && sec[0]-'0' == 0 || stoi(sec) > 255 || stoi(sec) < 0)
            {
                return "Neither";
            }
            for(char c: sec)
            {
                if(isdigit(c) == false)
                {
                    return "Neither";
                }
            }
        }
        return "IPv4";
    }
    string ipv6(vector<string> IP6)
    {
        for(string sec: IP6)
        {
            if(sec.size() > 4 || sec.size() < 1)
            {
                return "Neither";
            }
            for(char c: sec)
            {
                c = tolower(c);
                if(isxdigit(c) == false)
                {
                    return "Neither";
                }
            }
        }
        return "IPv6";
    }
};