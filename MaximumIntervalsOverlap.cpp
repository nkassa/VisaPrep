class Solution {

  public:
    vector<int> findMaxGuests(int Entry[], int Exit[], int N) 
    {
        // Your code goes here
        int maxi = 0;
        vector<int> ans;
        for(int i= 0; i < N; i++)
        {
            maxi = max(maxi, Exit[i]);
        }
        vector<int> list(maxi+2, 0);
        for(int i= 0; i < N; i++)
        {
            list[Entry[i]]++;
            list[Exit[i]+1]--;
        }
        maxi = 0;
        int sum = 0;
        for(int i = 0; i < list.size(); i++)
        {
            sum += list[i];
            if(maxi < sum)
            {
                maxi = sum;
                ans = {sum, i};
            }
        }
        return ans;
    }
};
//