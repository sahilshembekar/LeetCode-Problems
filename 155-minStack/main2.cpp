class MinStack {
    //Stack can be used 
    //Algo #2 1-stack approach 
    
    stack <int> st;
    //stack <int> minStack;
    int min;
    
public:
    MinStack() {
        
        min = INT_MAX;
        //minStack.push(min);
    }
    
    void push(int val) {
        //  st.push(val); //if you use this here it will not go through the if loop. Pretty logical why...
        if (val <= min) {
            st.push(min); // first push the previous min then update it            
            min = val;
        }
        st.push(val);

        //min = std::min(min,val);
        
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        
        if (top == min) {
            min = st.top();
            st.pop();
        }
        // st.pop();
        // minStack.pop();
        // min = minStack.top();
        
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