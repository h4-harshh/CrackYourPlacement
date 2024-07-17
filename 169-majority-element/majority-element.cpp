class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==res)
            {
                count++;
            }
            else if(nums[i]!=res)
            {
                count--;
            }
            if(count==0)
            {
                count=1;
                res=nums[i];
            }
        }
        return res;
    }
};