class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int MIN=std::numeric_limits<int>::max();
        for (int i=0; i<nums.size(); i++)
            MIN=min(nums[i],MIN);

        int result=0;
        for (int i=0; i<nums.size(); i++)
        {
            result+=nums[i]-MIN;
        }

        return result;
    }
};
