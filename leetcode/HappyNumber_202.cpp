class Solution {
public:
    bool helper(int n, unordered_set<int>& visited) {
        if(visited.count(n)) return false;
        if(n == 1) return true;
        
        visited.insert(n);
        int rst = 0;
        while(n) {
            int t = n % 10;
            rst += t * t;
            n /= 10;
        }
        return helper(rst, visited);
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        return helper(n, visited);
    }
};