class Solution {
public:
    int evaluate(int a, int b, string op)
{
    if (op == "+") 
    {
        return a + b;
    } 
    else if (op == "-") 
    {
        return a - b;
    } 
    else if (op == "*") 
    {
        return a * b;
    } 
    else if (op == "/") 
    {
        return a / b;
    } 
    else 
    {
        return -1; // Default case for unknown operations
    }
}
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
                int temp=evaluate(a,b,tokens[i]);
                st.push(temp);
                continue;
            }
            int k=stoi(tokens[i]);
            st.push(k);
        }
        return st.top();
    }
};