class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>result;

        int size=nums.size();
        vector<int>freq(size,0);

        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]-1]++;
        }

        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]>1)
            {
                result.push_back(i+1);
            }
        }
        return result;
    }
};