class MinStack {
    //Stack can be used 
    //Algo #1 2-stack approach 
    
    stack <int> st;
    stack <int> minStack;
    int min;
public:
    MinStack() {
        min = INT_MAX;
        minStack.push(min);
    }
    
    void push(int val) {
        st.push(val);
        if ( val <= min) {
            min = val;
        }
        minStack.push(min);

        //min = std::min(min,val);
        
    }
    
    void pop() {
        st.pop();
        minStack.pop();
        min = minStack.top();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */