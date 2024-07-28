class Solution {
public:
    int findPivot(vector<int>&arr)
    {
        int low=0;
        int high=arr.size()-1;

        while(low<high)
        {
            int mid=(low+(high-low)/2);

            if(arr[mid]>arr[high])
            {
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return high;
    }

    int binarySearch(vector<int>&arr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=(low+(high-low)/2);

            if(arr[mid]==target) return mid;

            else if(arr[mid]<target) low=mid+1;

            else high=mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int n=nums.size();

        int pivot_index=findPivot(nums);

        int idx=binarySearch(nums,0,pivot_index-1,target);

        if(idx!=-1)
            return idx;

        idx=binarySearch(nums,pivot_index,n-1,target);

        return idx;
    }
};