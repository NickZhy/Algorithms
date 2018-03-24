class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> rst;
        rst.push_back(1);
        int i = 0, j = 0, k = 0;
        for(int c = 1; c < n; ++c) {
            int t1 = rst[i] * 2, t2 = rst[j] * 3, t3 = rst[k] * 5;
            int r = min(t1, min(t2, t3));
            rst.push_back(r);
            i += r == t1;
            j += r == t2;
            k += r == t3;
        }
        return rst.back();
    }
};