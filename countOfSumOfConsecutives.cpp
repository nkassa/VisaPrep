
class Solution {
  public:
    int getCount(int N) {
        // code here
        int left = 1;
        int sum = 0;
        int ans = 0;
        if(N < 2)
        {
            return 0;
        }
        for(int right = 1; right < N+1; right++)
        {
            sum += right;
            if(sum == N && right - left + 1 >= 2)
            {
                ans++;
            }
            while(sum > N && right - left + 1 > 2)
            {
                sum -= left;
                left++;
            }
        }
        return ans;
    }
};