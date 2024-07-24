class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;

        int count=0;

        sort(nums.begin(),nums.end());

        while(start<end)
        {
            count+=nums[end--]-nums[start++];
        }

        return count;
    }
};