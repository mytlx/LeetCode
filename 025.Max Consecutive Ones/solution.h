class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int max = 0, cnt = 0;
        for(int i : nums)
        {
            if(i == 1)
                ++cnt;
            else
            {
                max = (cnt > max) ? cnt : max;
                cnt = 0;
            }
        }
        max = (cnt > max) ? cnt : max;
        return max;
    }
};
