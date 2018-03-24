class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int winSize;
    int sum;
    MovingAverage(int size) {
        assert(size > 0);
        winSize = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size() > winSize) {
            sum -= q.front();
            q.pop();
        }
        return double(sum) / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */