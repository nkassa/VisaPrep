class Solution {
public:
    string validIPAddress(string queryIP) 
    {
        vector<string> IP;
        if(queryIP.find('.') < queryIP.size())
        {
            string temp = "";
            stringstream ss(queryIP);
            while(getline(ss, temp, '.'))
            {
                IP.push_back(temp);
            }
            if(IP.size() == 4)
            {
                return ipv4(IP);
            }
        }
        if(queryIP.find(':') < queryIP.size())
        {
            string temp = "";
            stringstream ss(queryIP);
            while(getline(ss, temp, ':'))
            {
                IP.push_back(temp);
            }
            if(IP.size() == 8)
            {
                return ipv6(IP);
            }
        }
        return "Neither";
    }

    string ipv4(vector<string> IP)
    {
        for(string sec: IP)
        {
            if(sec.size() > 1 && sec[0]-'0' == 0 || stoi(sec) > 255 || stoi(sec) < 0)
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
    string ipv6(vector<string> IP)
    {
        for(string sec: IP)
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