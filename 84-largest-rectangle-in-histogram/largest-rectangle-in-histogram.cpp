class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> leftSmall(n);
    vector<int> rightSmall(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        int k = st.empty() ? 0 : st.top() + 1;
        leftSmall[i] = k;

        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        int k = st.empty() ? n - 1 : st.top() - 1;
        rightSmall[i] = k;

        st.push(i);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, (arr[i] * (rightSmall[i] - leftSmall[i] + 1)));
    }
    return maxi;
    }
};