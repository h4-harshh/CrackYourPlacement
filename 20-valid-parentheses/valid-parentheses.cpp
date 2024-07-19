class Solution {
public:
    bool find(char a,char b)
    {
        if((a=='(' && b==')')||(a=='{' && b=='}')||(a=='[' && b==']'))
        {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s)
        {
            if(!st.empty() && find(st.top(),x))
            {
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        
        return (st.empty());
    }
};