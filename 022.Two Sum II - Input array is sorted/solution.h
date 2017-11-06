class Solution {
public:
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
};
