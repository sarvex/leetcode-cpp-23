class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        reverse(satisfaction.begin(),satisfaction.end());

        int total = 0, presum = 0;
        int ret = std::numeric_limits<int>::min();
        for (int i=0; i<n; i++)
        {
            presum += satisfaction[i];
            total += presum;
            ret = max(ret, total);
        }
        return max(0,ret);

    }
};
