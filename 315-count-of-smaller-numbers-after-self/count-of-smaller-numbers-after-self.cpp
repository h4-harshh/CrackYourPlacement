class Solution {
public:
    void merge(vector<pair<int,int>>&nums,int low,int mid,int high,vector<int>&result)
    {
        

        vector<pair<int,int>>temp;
        int left=low,right=mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left].first<=nums[right].first)
            {
                temp.push_back(nums[right++]);
            }
            else{
                result[nums[left].second]+=high-right+1;
                temp.push_back(nums[left++]);
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left++]);
        }
        while(right<=high)
        {
            temp.push_back(nums[right++]);
        }

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }    
    }
    void mergeSort(vector<pair<int,int>>&nums1,int low,int high,vector<int>&result)
    {
        if(low>=high) return;
        int mid=(low+high)/2;

        mergeSort(nums1,low,mid,result);
        mergeSort(nums1,mid+1,high,result);
        merge(nums1,low,mid,high,result);
    }
    vector<int> countSmaller(vector<int>& nums) {

        vector<pair<int,int>>nums1;
        for(int i=0;i<nums.size();i++)
        {
            nums1.push_back({nums[i],i});
        }
        vector<int>result(nums.size(),0);
        mergeSort(nums1,0,nums.size()-1,result);
        return result;
    }
};