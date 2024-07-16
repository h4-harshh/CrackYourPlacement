class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool>mp;
        mp[nums[0]]=true;

        int ind=1;
        for(int i=1;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=true;
                nums[ind]=nums[i];
                ind++;
            }
        }
        return ind;
    }
};