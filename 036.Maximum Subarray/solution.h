#include <vector>
#include <climits>
#include <algorithm>

using std::vector; using std::max;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = INT_MIN, sum = 0;
        for(int i : nums)
        {
            sum = max(sum + i, i);
            res = max(sum, res);
        }
        return res;
    }
};
