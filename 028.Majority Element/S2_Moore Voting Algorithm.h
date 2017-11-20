class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1) return nums[0];
        int count = 0;
        int x;
        for(int i = 0; i < n; ++i)
        {
            if(count == 0)
            {
                x = nums[i];
                count = 1;
            }
            else if(nums[i] == x)
                ++count;
            else
                --count;
        }
        count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == x)
                ++count;
        }
        if(count > floor(n/2))
            return x;
        else
            return -1;
    }
};
