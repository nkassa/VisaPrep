class Solution {
  public:
    int peakElement(vector<int> &arr) 
    {
        // Your code here
        for(int i = 0; i < arr.size(); i++)
        {
            long long int left = arr[i] - arr[i-1];
            long long int right = arr[i] - arr[i+1];
            if(i == 0)
            {
                left = 0;
                if(right > 0)
                {
                    return i;
                }
            }
            if(i == arr.size()-1)
            {
                right = 0;
                if(left > 0)
                {
                    return i;
                }
            }
            if(left > 0 && right > 0)
            {
                return i;
            }
        }
        return 0;
    }
};