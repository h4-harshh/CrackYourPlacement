class Solution {
public:
    // approach 2 of 4
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        
        int product=1;
        int count_zero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) 
            {
                count_zero++;
                continue;
            }
            product*=nums[i];
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                if(count_zero>0)
                {
                    result[i]=0;
                }
                else{
                    result[i]=product/nums[i];
                }
            }
            else{
                if(count_zero>1)
                {
                    result[i]=0;
                }
                else{
                    result[i]=product;
                }
            }
        }
        return result;
    }
};