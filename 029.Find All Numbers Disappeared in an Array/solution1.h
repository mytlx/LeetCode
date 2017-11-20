class Solution {
public:
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
};
