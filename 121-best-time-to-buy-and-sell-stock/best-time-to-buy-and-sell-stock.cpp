class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();

        vector<int>mini(size);
        vector<int>maxi(size);
        mini[0]=prices[0];
        maxi[size-1]=prices[size-1];

        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<mini[i-1])
            {
                mini[i]=prices[i];
            }
            else{
                mini[i]=mini[i-1];
            }
        }
        for(int i=size-2;i>=0;i--)
        {
            if(prices[i]>maxi[i+1])
            {
                maxi[i]=prices[i];
            }
            else{
                maxi[i]=maxi[i+1];
            }
        }
        int res=0;
        for(int i=0;i<size;i++)
        {
            int curr=maxi[i]-mini[i];
            res=max(res,curr);
        }
        return res;
    }
};