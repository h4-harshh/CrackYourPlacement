class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();

        int min1=INT_MAX;
        int min2=min1;

        int max1=INT_MIN;
        int max2=max1;
        int max3=max2;

        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            //identifying min1 and min2
            if(min1>=val)
            {
                min2=min1;
                min1=val;
            }
            else if(min2>=val){
                min2=val;
            }

            //identifying 3 max values
            if(max1<=val)
            {
                max3=max2;
                max2=max1;
                max1=val;
            }
            else if(max2<=val)
            {
                max3=max2;
                max2=val;
            }
            else if(max3<=val)
            {
                max3=val;
            }
        }

        return max((min1*min2*max1),(max1*max2*max3));
    }
};