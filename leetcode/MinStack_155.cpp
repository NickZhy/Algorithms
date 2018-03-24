class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> data;
    vector<int> minEle;
    MinStack() {
        
    }
    
    void push(int x) {
        minEle.push_back(minEle.size()? min(minEle.back(), x): x);
        data.push_back(x);
    }
    
    void pop() {
        data.pop_back();
        minEle.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minEle.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */