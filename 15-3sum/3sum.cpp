class Solution {
public:

    void twoSum(vector<int>nums,int target,int ind,vector<vector<int>>&result)
    {
        int low=ind;
        int high=nums.size()-1;
        while(low<high)
        {
            if(nums[low]+nums[high]>target)
            {
                high--;
            }
            else if(nums[low]+nums[high]<target)
            {
                low++;
            }
            else
            {
                result.push_back({-target,nums[low],nums[high]});
                while(low<high && nums[low]==nums[low+1]) low++;
                while(low<high && nums[high]==nums[high-1]) high--;
                low++;
                high--;
            }
        }
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        vector<vector<int>>result;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            twoSum(nums,target-nums[i],i+1,result);
        }
        return result;
    }
};