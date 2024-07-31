class Solution {
public:
    // Approach 2 binary search
    int studentCount(vector<int>&nums,int maxSumAllowed)
    {
        int currNumSum=0;
        int currNumCount=1;
        for(int i=0;i<nums.size();i++){

            if(currNumSum+nums[i]<=maxSumAllowed)
            {
                currNumSum+=nums[i];
            }
            else{
                currNumCount++;
                currNumSum=nums[i];
            }
        }
        return currNumCount;
    }


    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) return -1;

        int low=*max_element(nums.begin(),nums.end());
        cout<<low<<endl;
        int high=accumulate(nums.begin(),nums.end(),0);
        cout<<high;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            int countNum=studentCount(nums,mid);

            if(countNum<=k)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};


