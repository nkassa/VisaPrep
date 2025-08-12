class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int idxNum1 = 0;
        int idxNum2 = 0;
        while(idxNum1 < nums1.size() && idxNum2 < nums2.size())
        {
            if(nums1[idxNum1] == nums2[idxNum2])
            {
                return nums1[idxNum1];
            }
            else if(nums1[idxNum1] > nums2[idxNum2])
            {
                idxNum2++;
            }
            else
            {
                idxNum1++;
            }
        }
        return -1;
    }
};