# [Contains Duplicate][1]
> Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

判断数组中是否有两个相同元素，可以用哈希表，还可以排序，对比相邻两个元素，如果有相同就返回真，否则返回false 
```cpp
bool containsDuplicate(vector<int>& nums) 
{
    if(nums.size() == 0 || nums.size() == 1) return false;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 1; ++i)
    {
        if(nums[i] == nums[i+1])
            return true;
    }
    return false;
}
```

[1]:https://leetcode.com/problems/contains-duplicate/description/
