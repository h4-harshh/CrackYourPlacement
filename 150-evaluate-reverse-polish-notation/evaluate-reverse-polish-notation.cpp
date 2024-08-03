class Solution {
public:
    unordered_map<string,function<int (int,int)>>mp={
        {"+",[](int a,int b) {return a+b;}},
        {"-",[](int a,int b) {return a-b;}},
        {"*",[](int a,int b) {return a*b;}},
        {"/",[](int a,int b) {return a/b;}}
    };
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int temp=mp[tokens[i]](a,b);
                st.push(temp);
                continue;
            }
            int k=stoi(tokens[i]);
            st.push(k);
        }
        return st.top();
    }
};