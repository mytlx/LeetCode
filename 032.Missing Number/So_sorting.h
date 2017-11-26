#include <vector>
#include <iterator>
#include <algorithm>

using std::vector; using std::iterator; using std::sort;

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int i;
        for(i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }
        return i;
    }
};
