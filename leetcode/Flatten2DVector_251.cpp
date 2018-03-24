class Vector2D {
    vector<vector<int>>& vec;
    int row, col;
public:
    Vector2D(vector<vector<int>>& vec2d): vec(vec2d) {
        row = col = 0;
        while(row < vec.size() && vec[row].size() == 0) ++row;
    }

    int next() {
        if(!hasNext()) return 0;
        int rst = vec[row][col++];
        if(col == vec[row].size()) {
            col = 0;
            ++row;
            while(row < vec.size() && vec[row].size() == 0) ++row;
        }
        return rst;
    }

    bool hasNext() {
        if(row >= vec.size()) return false;
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */