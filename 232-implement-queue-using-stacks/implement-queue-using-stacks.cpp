class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        while(!st1.empty())
        {
            st1.pop();
        }
        while(!st2.empty())
        {
            st2.pop();
        }
    }
    
    void push(int x) {
        if(st1.empty() && st2.empty())
        {
            st1.push(x);
            return;
        }

        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if(st1.empty())
        {
            return -1;
        }
        int x=st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        if(st1.empty())
        {
            return -1;
        }
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */