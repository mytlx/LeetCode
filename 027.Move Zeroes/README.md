# [Move Zeroes][1]
> Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.  
> For example, given `nums = [0, 1, 0, 3, 12]`, after calling your function, `nums` should be `[1, 3, 12, 0, 0]`.  
> 
> **Note:**
> 
> 1. You must do this **in-place** without making a copy of the array.  
> 2. Minimize the total number of operations.

这题主要有两个要求：

- 把所有0元素移到数组末尾
- 保持原来的非零元素顺序不变

用快慢指针，慢指针一开始指向0，快指针一开始指向1（需要首先判断数组size为0或1的情况），如果i指向的元素为0，那么就让j指针向前寻找非0元素，之后交换元素值，再把i和j同时向前移动一个单位。  
```cpp
void moveZeroes(vector<int>& nums) 
{
    if(nums.size() == 0 || nums.size() == 1) return;
    int i = 0, j = 1, temp = 0;
    while(j < nums.size())
    {
        if(nums[i] == 0)
        {
            if(nums[j] != 0)
            {
                nums[i] = nums[j];
                nums[j] = 0;
                ++i, ++j;
            }
            else
                ++j;
        }
        else
            ++i, ++j;

    }
}
```

更简单一些的方法类似，让i和j开始时同时指向0，让j往前跑，如果j对应的元素值不为0，则和i互换元素值，同时i和j向前移动一个单位。
```cpp
void moveZeroes(vector<int>& nums) 
{
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) 
  {
        if (nums[cur] != 0)
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
    }
}
```

[1]:https://leetcode.com/problems/move-zeroes/description/
