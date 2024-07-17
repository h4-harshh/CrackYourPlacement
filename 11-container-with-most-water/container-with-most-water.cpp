class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int low=0;
        int high=height.size()-1;

        int res=0;

        while(low<high)
        {
            int curr_area=min(height[low],height[high])*(high-low);
            res=max(res,curr_area);

            if(height[low]<height[high])
            {
                low++;
            }
            else{
                high--;
            }
        }
        return res;
    }
};