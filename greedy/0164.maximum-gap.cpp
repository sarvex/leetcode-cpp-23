class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        int N=nums.size();
        if (N<2) return 0;

        int MIN=std::numeric_limits<int>::max();
        int MAX=std::numeric_limits<int>::min();
        for (int i=0; i<nums.size(); i++)
        {
            MIN=min(MIN,nums[i]);
            MAX=max(MAX,nums[i]);
        }

        int bucket_size = max(1,(MAX-MIN)/(N-1));
        int bucket_nums = (MAX-MIN)/bucket_size+1;
        vector<int>bucket_min(bucket_nums,std::numeric_limits<int>::max());
        vector<int>bucket_max(bucket_nums,std::numeric_limits<int>::min());

        unordered_set<int>Set;
        for (int i=0; i<N; i++)
        {
            int idx=(nums[i]-MIN)/bucket_size;
            bucket_min[idx]=min(nums[i],bucket_min[idx]);
            bucket_max[idx]=max(nums[i],bucket_max[idx]);
            Set.insert(idx);
            //cout<<idx<<" "<<bucket_min[idx]<<" "<<bucket_max[idx]<<endl;
        }

        int result=std::numeric_limits<int>::min();
        int pre=0;
        for (int i=0; i<bucket_nums; i++)
        {
            if (Set.count(i)==0) continue;
            result=max(result,bucket_min[i]-bucket_max[pre]);
            pre = i;
        }

        return result;
    }
};
