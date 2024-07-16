class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) a++;
            if(nums[i]==1) b++;
            if(nums[i]==2) c++;
        }
        int k=0;
        while(a--)
        {
            nums[k++]=0;
        }
        while(b--)
        {
            nums[k++]=1;
        }
        while(c--)
        {
            nums[k++]=2;
        }

    }
};