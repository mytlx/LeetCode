# [Find All Numbers Disappeared in an Array][1]
> Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.  
> 
> Find all the elements of [1, n] inclusive that do not appear in this array.  
> 
> Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.  
> 
> **Example:**  
> ```cpp
> Input:  
> [4,3,2,7,8,2,3,1]  
> Output:  
> [5,6]
> ```

这题的意思是给定一个大小为n的数组，数组元素1~n，有的出现一次，有的出现两次，所以有一些元素不会出现，找到不出现的元素。时间复杂度O(n)，空间复杂度O(1)。

### 方法一：元素归位法---TLE
元素归位法，就是将元素放到下标对应的位置。  
```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) 
  {
      vector<int> ret;
      int n = nums.size();
      int temp;
      for(int i = 0; i < n; ++i)
      {
          while(nums[i] != i + 1 && nums[nums[i]-1] != nums[i])  //以免两个元素值相同，陷入死循环
          {
              temp = nums[i];
              nums[i] = nums[nums[i]-1];
              nums[nums[i]-1] = temp;
          }
      }

      for(int i = 0; i < n; ++i)
      {
          if(nums[i] != i + 1)
              ret.push_back(i+1);
      }
      return ret;
  }
```
中间交换部分可以写成：
```cpp
if(nums[i] != i + 1 && nums[nums[i]-1] != nums[i])  //以免两个元素值相同，陷入死循环
{
    temp = nums[i];
    nums[i] = nums[nums[i]-1];
    nums[nums[i]-1] = temp;
    --i;
}
```
### 方法二：取余法---AC
循环一次，将每个元素对应位置加n+1，所以如果该位置的元素出现0次，则该位置加0；如果该位置的元素出现1次，则该位置加n+1；如果该位置的元素出现2次，则该位置加2(n+1)。最后各个位置元素除以n+1，如果结果为0，则该位置本该对应的元素未出现过。  
```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) 
{
    vector<int> ret;
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
        nums[nums[i] % (n+1)-1] += (n+1);
    }

    for(int i = 0; i < n; ++i)
    {
        if(nums[i] / (n+1) == 0)
            ret.push_back(i+1);
    }
    return ret;
}
```
### 方法三：取负法---AC
跟方法二有些许相似，取负法就是将每个元素对应位置的元素取负值，如果最后哪个位置的元素为正值，则说明这个位置本该对应的元素未出现过。
```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) 
{
    vector<int> ret;
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0)
            nums[index] = -nums[index];
    }

    for(int i = 0; i < n; ++i)
    {
        if(nums[i] > 0)
            ret.push_back(i+1);
    }
    return ret;
}
```

[1]:https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
