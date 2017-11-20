class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        if(nums.size() == 0 || nums.size() == 1) return;
        int i = 0, j = 1, temp = 0;
        while(j < nums.size())
        {
            if(nums[i] == 0)
            {
                if(nums[j] != 0)
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    ++i, ++j;
                }
                else
                    ++j;
            }
            else
                ++i, ++j;
        }
    }
};
