# [Majority Element][1]
> Given an array of size n, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋` times.  
> 
> You may assume that the array is non-empty and the majority element always exist in the array.

首先想到的是哈希表，其次是排序
### 方法一：sort
排序过后，因为超过`⌊ n/2 ⌋`个，所以第`⌊ n/2 ⌋ + 1`个数肯定是Majority Element
```cpp
int majorityElement(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    return nums[floor(nums.size() / 2)];
}
```
### 方法二：Moore Voting Algorithm
还有一种解法是，同时去掉两个不相同的数，最后剩下的一定是Majority Element。
```cpp
int majorityElement(vector<int>& nums) 
{
    int n = nums.size();
    if(n == 1) return nums[0];
    int count = 0;
    int x;
    for(int i = 0; i < n; ++i)
    {
        if(count == 0)
        {
            x = nums[i];
            count = 1;
        }
        else if(nums[i] == x)
            ++count;
        else
            --count;
    }
    count = 0;
    for(int i = 0; i < n; ++i)
    {
        if(nums[i] == x)
            ++count;
    }
    if(count > floor(n/2))
        return x;
    else
        return -1;
}
```
[1]:https://leetcode.com/problems/majority-element/description/

