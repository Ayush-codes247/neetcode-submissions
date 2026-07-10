class MinStack {
public:
    stack<int> mainStack;
    stack<int> helper;
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if(helper.empty()){
            helper.push(val);
        }else{
            helper.push(min(val, helper.top()));
        }
    }
    
    void pop() {
        if(!mainStack.empty()) mainStack.pop();
        if(!helper.empty()) helper.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return helper.top();
    }
};
