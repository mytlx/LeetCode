# [Array Partition I][1]
> Given an array of **2n** integers, your task is to group these integers into **n** pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.  
> 
> **Example 1:**  
> <pre><b>Input:</b> [1,4,3,2]  
> <b>Output:</b> 4  
> <b>Explanation:</b> n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).  
> </pre>
> **Note:**  
> 1. n is a positive integer, which is in the range of [1, 10000].  
> 2. All the integers in the array will be in the range of [-10000, 10000].

这题的意思是将数组分成n组，看怎样分组能使各组最小值之和最大。要最小值之和最大，肯定是先将数组**排序**，之后临近分组，可使和最大。

    int arrayPairSum(vector<int>& nums) 
    {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }


[1]:https://leetcode.com/problems/array-partition-i/description/
