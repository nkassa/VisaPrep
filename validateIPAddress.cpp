class Solution {
public:
    string validIPAddress(string queryIP) 
    {
        if(queryIP.size() == 0 || queryIP.back() == '.' || queryIP.back() == ':')
        {
            return "Neither";
        }
        if(queryIP.find('.') < string::npos)
        {
            vector<string> IP;
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
        if(queryIP.find(':') < string::npos)
        {
            vector<string> IP;
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
            if(sec.empty() || sec.size() > 1 && sec[0] == '0' || sec.size() > 3)
            {
                return "Neither";
            }
            for(char c: sec)
            {
                if(!isdigit(c))
                {
                    return "Neither";
                }
            }
            int num = stoi(sec);
            if(num < 0 || num > 255)
            {
                return "Neither";
            }
        }
        return "IPv4";
    }
    string ipv6(vector<string> IP)
    {
        for(string sec: IP)
        {
            if(sec.size() > 4 || sec.empty())
            {
                return "Neither";
            }
            for(char c: sec)
            {
                if(!isxdigit(c))
                {
                    return "Neither";
                }
            }
        }
        return "IPv6";
    }
};