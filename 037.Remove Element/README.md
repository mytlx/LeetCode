# [Remove Element][1]
> Given an array and a value, remove all instances of that value **in-place** and return the new length.  
> 
> Do not allocate extra space for another array, you must do this by **modifying the input array** in-place with O(1) extra memory.  
> 
> The **order** of elements **can be changed**. It doesn't matter what you leave beyond the new length.  
> 
> **Example:**  
> ```cpp
> Given nums = [3,2,2,3], val = 3,  
> Your function should return length = 2, with the first two elements of nums being 2.
> ```
删除数组中跟所给元素相等的所有元素，并返回删除后的数组长度，**可以打乱数组顺序**。

### 方法一：
因为可以打乱数组顺序，所有可以循环遍历数组，若元素相等，则将数组最后一个元素赋值给这个元素，并将循环条件n减一；若不等，循环变量往前走。
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[n-1];
                --n;
            }
            else
                ++i;
        }
        return n;
    }
};
```
### 方法二：two pointers
与[**Remove Duplicates from Sorted Array**][2]相似，快慢指针，快指针往前走，当遇到和val相等的元素时，加一跳过，不相等时，把快指针对应元素值赋给慢指针，两指针同时向前走一步。
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) 
        {
            if (nums[j] != val) 
            {
              nums[i] = nums[j];
              ++i;
            }
        }
        return i;
    }
};
```
[1]:https://leetcode.com/problems/remove-element/description/
[2]:https://github.com/mytlx/LeetCode/tree/master/024.Remove%20Duplicates%20from%20Sorted%20Array
