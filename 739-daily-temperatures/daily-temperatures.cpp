class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();

        vector<int>res(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }
            int k=st.empty()?0:st.top();
            st.push(i);
            res[i]=k==0?0:k-i;
        }
        return res;
    }
};