class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>q(n, std::numeric_limits<int>::max());
        for (int i=0; i<n; i++)
        {
            auto iter = lower_bound(q.begin(),q.end(),nums[i]);
            *iter = nums[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (q[i] != std::numeric_limits<int>::max())
                return i + 1;
        }
        return 0;
    }
};
