# [Maximum Subarray][1]
> Find the contiguous subarray within an array (containing at least one number) which has the largest sum.  
> 
> For example, given the array `[-2,1,-3,4,-1,2,1,-5,4]`,  
> the contiguous subarray `[4,-1,2,1]` has the largest sum = `6`.

求最大子数组之和  

**动态规划**问题，**Kadane's algorithm**，如果前面连续加上当前元素大于当前元素，则继续走；如果小于当前元素，则需要另起。
```cpp
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
```

[1]:https://leetcode.com/problems/maximum-subarray/description/
