class MyQueue {
public:
    stack<int>input;
    stack<int>output;
    int peekl;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty())
        {
            peekl=x;
            input.push(x);
        }
        else{
            input.push(x);
        }
    }
    
    int pop() {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int k=output.top();
        output.pop();
        return k;
    }
    
    int peek() {
        if(output.empty()) return peekl;
        else return output.top();
    }
    
    bool empty() {
        return (input.empty() && output.empty());
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