#include <vector>
#include <algorithm>

using std::vector; using std::max;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int anchor = 0, ret = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i - 1] >= nums[i])
                anchor = i;
            ret = max(ret, i - anchor + 1);
        }
        return ret;
    }
};
