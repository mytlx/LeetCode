# [Valid Anagram][1]
> Given two strings s and t, write a function to determine if t is an anagram of s.  
> 
> **For example**,  
> s = "anagram", t = "nagaram", return true. 
> s = "rat", t = "car", return false.  
> 
> **Note:**  
> You may assume the string contains only lowercase alphabets.

判断连个字符串中字母是不是相同但是顺序不同。  

这道题很简单，先判断两个字符串长度，若长度相同，排序后比较两个字符串是否相同就行。  
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t)
            return true;
        else
            return false;    
    }
};
```

[1]:https://leetcode.com/problems/valid-anagram/description/
