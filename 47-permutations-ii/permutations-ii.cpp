class Solution {
public:
    int n;
    vector<vector<int>>result;
    
    void solve(vector<int>&nums,int idx)
    {
        if(idx>=n)
        {
            result.push_back(nums);
            return;
        }

        unordered_set<int>unique_set;
        for(int i=idx;i<n;i++)
        {
            if(unique_set.find(nums[i])!=unique_set.end())
            {
                continue;
            }
            unique_set.insert(nums[i]);
            swap(nums[i],nums[idx]);
            solve(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();

        solve(nums,0);

        return result;
    }
};