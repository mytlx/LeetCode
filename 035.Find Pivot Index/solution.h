#include <vector>
#include <climits>

using std::vector;

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int leftSum = 0, sum = 0;
        for(int i : nums)
            sum += i;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(leftSum == sum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }        
        return -1;
    }
};
