//取余法
class Solution {
public:
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
};
