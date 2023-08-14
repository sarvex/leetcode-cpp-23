class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        int n = arr1.size();
        arr1.insert(arr1.begin(),0);
        sort(arr2.begin(),arr2.end());
        auto dp = vector<vector<int>>(n+1, vector<int>(n+1,std::numeric_limits<int>::max()));
        dp[0][0] = std::numeric_limits<int>::min();

        for (int i=1; i<=n; i++)
            for (int k=0; k<=i; k++)
            {
                if (arr1[i] > dp[i-1][k])
                    dp[i][k] = min(dp[i][k], arr1[i]);

                if (k>=1)
                {
                    auto iter = upper_bound(arr2.begin(), arr2.end(), dp[i-1][k-1]);
                    if (iter!=arr2.end()) dp[i][k] = min(dp[i][k], *iter);
                }
            }

        int ret = std::numeric_limits<int>::max();
        for (int k=0; k<=n; k++)
            if (dp[n][k]!=std::numeric_limits<int>::max()) {
                ret = k;
                break;
            }

        return ret == std::numeric_limits<int>::max() ? -1: ret;
    }
};
