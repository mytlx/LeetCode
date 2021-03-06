# [Maximum Product of Three Numbers][1]
> Given an integer array, find three numbers whose product is maximum and output the maximum product.  
> **Example 1:**  
> ```cpp 
> Input: [1,2,3]  
> Output: 6
> ```
> **Example 2:**  
> ```cpp
> Input: [1,2,3,4]  
> Output: 24  
> ```
> **Note:**  
> 1. The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].  
> 2. Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

这题能想到大概三个方法：

- Brute Force
- sorting
- find max Elements

先说第一种，三层循环寻找最大乘积，必然TLE。  
第二种，就是我用的方法，先把数组从小到大排序，因为可能有负值，所以最大乘积可能是**后三个元素**或者**前两个和最后一个**。  
第三种，循环一次，用多个if找到，前两个最小的和最大的三个，道理同第二种。  
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max1 = nums[n-1] * nums[n-2] * nums[n-3];  
        int max2 = nums[0] * nums[1] * nums[n-1];
        return max(max1, max2);
    }
};
```

[1]:https://leetcode.com/problems/maximum-product-of-three-numbers/description/
