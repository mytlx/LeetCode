class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int i = 0;
        while(i < bits.size() - 1)
        {
            if(bits[i] == 0)
                i += 1;
            else 
                i += 2;
        }
        return i == bits.size() - 1;
    }
};
