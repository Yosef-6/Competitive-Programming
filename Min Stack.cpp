class MinStack {
public:
    MinStack():m_stack(),m_minStack() {
        
    }
    
    void push(int val) {
        m_stack.push(val);
        if(m_minStack.empty())
            m_minStack.push(val);
        else
            if(m_minStack.top() >= val )
                m_minStack.push(val);
        
    }
    
    void pop() {
        int top = m_stack.top();m_stack.pop();
        if(m_minStack.top() == top)
            m_minStack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_minStack.top();
    }
    stack<int>m_stack;
    stack<int>m_minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
