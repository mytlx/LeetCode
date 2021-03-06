# [Two Sum II - Input array is sorted][1]
> Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.  
> 
> The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.  
> 
> You may assume that each input would have exactly one solution and you may not use the same element twice.  
> 
> **Input:** numbers={2, 7, 11, 15}, target=9  
> **Output:** index1=1, index2=2

一开始用暴力破解法，TLE  


    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> index;
        for(size_t i = 0; i < numbers.size() - 1; i++)
        {
            for(size_t j = i + 1; j < numbers.size(); j++)
            {
                if(target == numbers[i] + numbers[j])
                {
                    index.push_back(i+1);
                    index.push_back(j+1);
                    break;
                }
            }
        }
        return index;       
    }


因为数组是按照**升序**排列的，所以可以用**两个指针**，一个指向第一个元素，一个指向最后一个元素，将两个指针对应的值相加与target比较，
若相等，保存index；若target小，则后面指针向前移动一个单位；若target大，则将前面指针向后移动一个单位。
题目要求数组下标不能从0开始，所以保存到index里的**下标要加1**。

    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> index;
        int i = 0, j = numbers.size() - 1;
        while(i != j)
        {
            if(target == numbers[i] + numbers[j])
            {
                index.push_back(i+1);
                index.push_back(j+1);
                break;
            }
            else if(target < numbers[i] + numbers[j])
                j--;
            else
                i++;
        }
        return index;       
    }


[1]:https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
