class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        long MAX = 1;
        long MIN = 1;
        long ret =  std::numeric_limits<int>::min();

        for (int i=0; i<nums.size(); i++)
        {
            long MAX_tmp = MAX, MIN_tmp = MIN;
            MAX = max(max(MAX_tmp*nums[i],MIN_tmp*nums[i]),(long)nums[i]);
            MIN = min(min(MAX_tmp*nums[i],MIN_tmp*nums[i]),(long)nums[i]);
            ret = max(ret,MAX);
        }
        return result;
    }
};
