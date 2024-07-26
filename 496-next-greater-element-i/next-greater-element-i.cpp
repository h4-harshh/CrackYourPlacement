class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        unordered_map<int,int>mp;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }

            int k=st.empty()?-1:st.top();
            mp[nums2[i]]=k;
            st.push(nums2[i]);
        }

        vector<int>res(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            res[i]=mp[nums1[i]];
        }
        return res;
    }
};