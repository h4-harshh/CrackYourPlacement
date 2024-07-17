class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;

        vector<int>prefix(n,0);
        prefix[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }

        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(prefix[i]-k)!=mp.end()){
                count+=mp[prefix[i]-k];
            }
                mp[prefix[i]]++;
        }
        return count;
    }
};