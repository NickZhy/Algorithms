class Solution {
    unordered_map<int, int> mem;
public:
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n <= 1) return 1;
        if(mem.count(n)) return mem[n];
        int rst = climbStairs(n - 1) + climbStairs(n - 2);
        mem[n] = rst;
        return rst;
    }
};