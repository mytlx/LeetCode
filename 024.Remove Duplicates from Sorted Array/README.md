# [Remove Duplicates from Sorted Array][1]
> Given a sorted array, remove the duplicates [in-place][2] such that each element appear only once and return the new length.  
> 
> Do not allocate extra space for another array, you must do this by **modifying the input array** [in-place][2] with O(1) extra memory.  
> 
> **Example:**  
> 
> <pre>Given nums = [1,1,2],  
> 
> Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.  
> It doesn't matter what you leave beyond the new length.</pre>

双指针的应用，一个慢指针i，一个快指针j，当快慢指针相等时，快指针继续走，跳过相等的元素，当不相等时，将j的值赋给i+1  

	int i = 0;
    for(int j = 0;j < nums.size(); j++)
    {
        if(nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }


[1]:https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
[2]:https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95/8010757?fr=aladdin
