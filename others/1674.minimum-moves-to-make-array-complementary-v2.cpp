class Solution {
public:
    int minMoves(vector<int>& nums, int limit)
    {
        map<int,int>diff;
        int n = nums.size();
        for (int i=0; i<n/2; i++)
        {
            int a = min(nums[i],nums[n-1-i]);
            int b = max(nums[i],nums[n-1-i]);

            diff[2]+=2;
            diff[1+a]-=1;
            diff[a+b]-=1;
            diff[a+b+1]+=1;
            diff[limit+b+1]+=1;
        }

        int ret = std::numeric_limits<int>::max();
        int count = 0;
        for (auto x: diff)
        {
            count += x.second;
            ret = min(ret, count);
        }
        return ret;
    }
};
