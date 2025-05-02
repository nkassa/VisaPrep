class Solution {
public:
    string validIPAddress(string queryIP) 
    {
        int n = queryIP.size();
        if(n >= 1 && (queryIP[n-1] == '.' || queryIP[n-1] == ':'))
        {
            return "Neither";
        }
        if(queryIP.find('.') < queryIP.size())
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
        if(queryIP.find(':') < queryIP.size())
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
            int num = 0;
            int digit = 1;
            for(int i = sec.size()-1; i >= 0; i--)
            {
                if(!isdigit(sec[i]))
                {
                    return "Neither";
                }
                num += (sec[i]-'0') * digit;
                digit *= 10;
            }
            cout << num << endl; 
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