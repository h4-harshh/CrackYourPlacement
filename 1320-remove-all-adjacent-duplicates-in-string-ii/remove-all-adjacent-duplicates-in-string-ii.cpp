class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        if(s.length()<k) return s;

        for(auto x:s)
        {
            if(st.empty() || st.top().first!=x) st.push({x,1});
            else{
                    auto prev=st.top();
                    st.pop();
                    st.push({x,prev.second+1});
            }            
            if(st.top().second==k) st.pop();
        }

        string result="";
            while(!st.empty())
            {
                auto prev=st.top();
                st.pop();
                int freq=prev.second;
                while(freq--){
                    // result=prev.first+result;
                    result.push_back(prev.first);
                }
            }
            reverse(result.begin(),result.end());
            return result;
    }
};