class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> data;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++data[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto p: data) {
            int other = value - p.first;
            if(other == p.first) {
                if(p.second > 1) return true;
            } else {
                if(data.count(other) && data[other] > 0) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */