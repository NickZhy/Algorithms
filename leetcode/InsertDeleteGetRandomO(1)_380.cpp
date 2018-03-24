class RandomizedSet {
private:
    unordered_map<int, int> val2Index;
    unordered_map<int, int> index2Val;
    int count;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        count = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(val2Index.count(val)) return false;
        index2Val[count] = val;
        val2Index[val] = count++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!val2Index.count(val)) return false;
        --count;
        if(val2Index[val] == count) {
            val2Index.erase(val);
            index2Val.erase(count);
        } else {
            int idx = val2Index[val];
            int lastVal = index2Val[count];
            index2Val.erase(count);
            val2Index.erase(val);
            val2Index[lastVal] = idx;
            index2Val[idx] = lastVal;
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(count == 0) return 0;
        int idx = rand() % count;
        return index2Val[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */