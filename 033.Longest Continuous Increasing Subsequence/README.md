# [Longest Continuous Increasing Subsequence][1]
> Given an unsorted array of integers, find the length of longest continuous increasing subsequence.  
> 
> **Example 1:**
> ```cpp
>	Input: [1,3,5,4,7]
>	Output: 3
>	Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
>	Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
> ```
> **Example 2:**
> ```cpp
>	Input: [2,2,2,2,2]
>	Output: 1
>	Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
> ```
> **Note:** Length of the array will not exceed 10,000.

这道题的思路是，循环比较元素，如果递增，计数器加一，如果非递增，如果比记录中的max大，将max更新，然后计数器清零，最后返回max。
```cpp
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
```
**Sliding Window**，与上面思想类似，但是简单许多。
```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {     
        int anchor = 0, ret = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i-1] >= nums[i])
                anchor = i;
            ret = max(ret, i - anchor + 1);
        }
        return ret;
    }
};
```
[1]:https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
