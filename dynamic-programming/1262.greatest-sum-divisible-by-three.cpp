class Solution {
public:
    int maxSumDivThree(vector<int>& nums)
    {
        vector<int>dp(3);
        dp[1] = std::numeric_limits<int>::min();
        dp[2] = std::numeric_limits<int>::min();

        for (int i=0; i<nums.size(); i++)
        {
            auto dp_temp = dp;
            for (int j=0; j<3; j++)
            {
                dp[j] = max(dp_temp[j], dp_temp[(j-nums[i]%3+3)%3]+nums[i]);
            }
        }
        return dp[0];
    }
};
