// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int tmp;
    bool peeked;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    tmp = 0;
        peeked = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        assert(hasNext());
        if(!peeked) {
           tmp = Iterator::next();
           peeked = true;
        }
        return tmp;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        assert(hasNext());
	    if(peeked) {
            peeked = false;
            return tmp;
        }
        return Iterator::next();
	}

	bool hasNext() const {
	    if(peeked) return true;
        return Iterator::hasNext();
	}
};