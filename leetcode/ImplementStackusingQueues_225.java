class MyStack {

    /** Initialize your data structure here. */
    Queue<Integer> q = new ArrayDeque<Integer>();
    public MyStack() {
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        Queue<Integer> tmp = new ArrayDeque<Integer>();
        while(q.size() > 1) tmp.add(q.poll());
        int rst = q.poll();
        q = tmp;
        return rst;
    }
    
    /** Get the top element. */
    public int top() {
        Queue<Integer> tmp = new ArrayDeque<Integer>();
        while(q.size() > 1) tmp.add(q.poll());
        int rst = q.poll();
        tmp.add(rst);
        q = tmp;
        return rst;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */