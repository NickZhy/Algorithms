class Solution {
    unordered_map<int, int> mem;
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(mem.count(n)) return mem[n];
        int rst = 0;
        for(int i = 0; i < n; ++i) {
            int l = numTrees(i);
            int r = numTrees(n - 1 - i);
            rst += l * r;
        }
        mem[n] = rst;
        return rst;
    }
};