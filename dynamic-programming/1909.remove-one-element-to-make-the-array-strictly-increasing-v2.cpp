class Solution {
public:
    bool canBeIncreasing(vector<int>& nums)
    {
        int max0 = std::numeric_limits<int>::min(), max1 = std::numeric_limits<int>::min();

        for (auto x: nums)
        {
            int max0_tmp = max0, max1_tmp = max1;

            max0 = (x > max0_tmp) ? x : std::numeric_limits<int>::max();

            max1 = max0_tmp;
            if (x > max1_tmp)
                max1 = min(max1, x);

            if (max1==std::numeric_limits<int>::max())
                return false;
        }

        return true;
    }
};
