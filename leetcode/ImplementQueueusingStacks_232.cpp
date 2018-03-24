class MyQueue {
    vector<int> stk;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        vector<int> tmp;
        while(stk.size()) {
            tmp.push_back(stk.back());
            stk.pop_back();
        }
        int rst = tmp.back();
        tmp.pop_back();
        while(tmp.size()) {
            stk.push_back(tmp.back());
            tmp.pop_back();
        }
        return rst;
    }
    
    /** Get the front element. */
    int peek() {
        vector<int> tmp;
        while(stk.size()) {
            tmp.push_back(stk.back());
            stk.pop_back();
        }
        int rst = tmp.back();
        while(tmp.size()) {
            stk.push_back(tmp.back());
            tmp.pop_back();
        }
        return rst;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */