class MyQueue {
public:
    MyQueue():tempStack(),mainStack() {
        
    }
    
    void push(int x) {
        tempStack.push(x);
    }
    
    int pop() {
        int top = 0;
        while(!tempStack.empty()){
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
     
        top = mainStack.top();
        mainStack.pop();
    
        while(!mainStack.empty()){
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        return top;
    }
    
    int peek() {
        int top = 0;
        while(!tempStack.empty()){
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
   
        top = mainStack.top();
        while(!mainStack.empty()){
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        return top;
        
    }
    
    bool empty() {
        return tempStack.empty();
    }
    stack<int> tempStack;
    stack<int> mainStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
