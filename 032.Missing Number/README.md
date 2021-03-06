# [Missing Number][1]
> Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
>
> **For example,**  
> Given nums = `[0, 1, 3]` return `2`.
> 
>**Note:**  
> Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

这道题貌似方法很多，我主要用了两种方法。
  
### 方法一：sorting
先把数组从小到大排序，循环比较index和value，如果不相等，返回index值。需要注意的是，如果缺少的是最后一个元素，循环中比较不出，所以循环外应该返回数组长度。
```cpp
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
```
### 方法二：异或
按位异或，相同为0，不同为1，所以循环异或index和value，注意要异或上数组长度，原因同上。
```cpp
class Solution {  
public:  
    int missingNumber(vector<int>& nums) 
  {  
        int res=0;  
        for(int i = 0; i < nums.size(); ++i)
    {  
            res ^= (i+1) ^ nums[i];  
        }  
        return res;  
    }  
};  
```
[1]:https://leetcode.com/problems/missing-number/description/
