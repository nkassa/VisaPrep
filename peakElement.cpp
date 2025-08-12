class Solution {
  public:
    int peakElement(vector<int> &arr) 
    {
        // Your code here
        int left = 0;
        int right = arr.size()-1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(arr[mid] > arr[mid+1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};