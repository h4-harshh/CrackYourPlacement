class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int low=j+1;
                int high=n-1;
                while(low<high)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[low];
                    sum+=nums[high];
                    if(sum<target) low++;
                    else if(sum>target) high--;
                    else
                    {
                        result.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                        while(low<high && nums[low]==nums[low-1]) low++;
                        while(low<high && nums[high]==nums[high+1]) high--;
                    }                    
                }
            }
        }
        return result;
    }
};