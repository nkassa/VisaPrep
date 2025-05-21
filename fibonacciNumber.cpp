class Solution {
public:
    vector<int> list;
    int fib(int n) 
    {
        list = vector(n+1, -1);
        if(n <= 1)
        {
            return n;
        }
        list[0] = 0;
        list[1] = 1;
        return dp(n);
    }
    int dp(int n)
    {
        if(list[n] != -1)
        {
            return list[n];
        }
        list[n] = dp(n-1) + dp(n-2);
        return list[n];
    }
};