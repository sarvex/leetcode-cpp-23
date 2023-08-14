class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        jobDifficulty.insert(jobDifficulty.begin(),0);
        auto dp = vector<vector<int>>(n+1, vector<int>(d+1, std::numeric_limits<int>::max()/2));

        dp[0][0] = 0;

        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(d,i); k++)
            {
                int mx = jobDifficulty[i];
                for (int j=i; j>=k; j--)
                {
                    mx = max(mx, jobDifficulty[j]);
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1]+mx);
                }
            }

        if (dp[n][d]>=std::numeric_limits<int>::max()/2) return -1;
        else return dp[n][d];
    }
};
