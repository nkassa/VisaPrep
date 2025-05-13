class Solution {
  public:
    int peakElement(vector<int> &arr) 
    {
        
        // Your code here
        if(arr.size() == 1)
        {
            return 0;
        }
        for(int i = 1; i < arr.size()-1; i++)
        {
            long long int left = arr[i] - arr[i-1];
            long long int right = arr[i] - arr[i+1];
            if(left >= 0 && right >= 0)
            {
                return i;
            }
        }
        if(arr[0] > arr[1])
        {
            return 0;
        }
        if(arr[arr.size()-1] > arr[arr.size()-2] )
        {
            return arr.size()-1;
        }
        return -1;
    }
};