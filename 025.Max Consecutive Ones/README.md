# [Max Consecutive Ones][1]
> Given a binary array, find the maximum number of consecutive 1s in this array.  
> ```
> Example 1: 
> Input: [1,1,0,1,1,1]  
> Output: 3  
> Explanation: The first two digits or the last three digits are consecutive 1s.  
>     The maximum number of consecutive 1s is 3.   
> ```
> **Note:** 
>  
> - The input array will only contain 0 and 1.
> - The length of input array is a positive integer and will not exceed 10,000

这道题让我们求最大连续1的个数，我们可以遍历一遍数组，用一个计数器cnt来统计1的个数，方法是如果当前数字为0，
那么cnt重置为0，如果不是0，cnt自增1，保存最大值到max中。


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

[1]:https://leetcode.com/problems/max-consecutive-ones/description/
