class ZigzagIterator {
    int col;
    bool first;
    vector<int> &vec1, &vec2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2): vec1(v1), vec2(v2) {
        col = 0;
        first = (vec1.size() != 0);
    }

    int next() {
        if(!hasNext()) return 0;
        int rst = first? vec1[col]: vec2[col];
        if(first) {
            if(col >= vec2.size()) 
                ++col;
            else 
                first = false;
        } else {
            ++col;
            if(col < vec1.size())
                first = true;
        }
        return rst;
    }

    bool hasNext() {
        return col < vec1.size() || col < vec2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */