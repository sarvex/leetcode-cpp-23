class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k)
    {
        unordered_map<long,vector<int>>Map;
        long sum=0;
        int result=std::numeric_limits<int>::min();

        nums.insert(nums.begin(),0);

        for (int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            Map[sum].push_back(i);

            int temp = sum-k;
            if (Map.find(temp)!=Map.end())
            {
                result = max(result, i-Map[temp][0]);
            }
        }

        if (result==std::numeric_limits<int>::min()) result=0;

        return result;

    }
};
