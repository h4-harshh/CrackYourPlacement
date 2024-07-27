class Solution {
public:
    stack<char>st;
    bool backspaceCompare(string s, string t) {
        for(auto x:s)
        {
            if(x=='#' && st.empty()) continue;
            if(x=='#' && !st.empty())
            {
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        s="";
        while(!st.empty())
        {
            s=st.top()+s;
            st.pop();
        }
        cout<<s<<endl;

        for(auto x:t)
        {
            if(x=='#' && st.empty()) continue;
            if(x=='#' && !st.empty())
            {
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        t="";
        while(!st.empty())
        {
            t=st.top()+t;
            st.pop();
        }
        cout<<t<<endl;

        return t==s;
    }
};