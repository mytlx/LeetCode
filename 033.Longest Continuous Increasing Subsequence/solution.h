#include <vector>
using std::vector;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int count = 1, max = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1])
            {
                ++count;
            }
            else
            {
                max = (max > count? max : count);
                count = 1;
            }    
        }
        max = (max > count? max : count);
        return max;       
    }
};
