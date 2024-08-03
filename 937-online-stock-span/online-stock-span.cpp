class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
            int curr_span=1;
            while(!st.empty() && st.top().first<=price)
            {
                curr_span+=st.top().second;
                st.pop();
            }
            st.push({price,curr_span});
        return curr_span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */