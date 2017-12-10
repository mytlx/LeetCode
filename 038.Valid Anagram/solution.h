#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using std::string;  using std::sort;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else
            return false;
    }
};
