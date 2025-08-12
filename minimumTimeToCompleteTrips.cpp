class Solution {
public:
    int limit;
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        limit = totalTrips;
        long long left = 1;
        long long right = LLONG_MAX;
        while(left <= right)
        {
            long long mid = left + (right - left) / 2;
            if(check(mid, time))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(long long mid, vector<int> time)
    {
        long long sum = 0;
        for(auto ti: time)
        {
            sum += mid / ti;
        }
        return sum >= limit;
    }
};