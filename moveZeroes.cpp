class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int left = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            if(nums[right] != 0 && nums[left] == 0)
            {
                nums[left] = nums[right];
                nums[right] = 0;
                left++;
            }
            else if(nums[left] != 0)
            {
                left++;
            }
        }
    }
};