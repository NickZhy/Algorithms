class Solution {
public:
    void helper(int n, int pos, int k, vector<int>& stk, vector<vector<int>>& rst) {
        if(n - pos + 1 < k || !k) {
            if(!k) rst.push_back(stk);
            return;
        }
        stk.push_back(pos);
        helper(n, pos + 1, k - 1, stk, rst);
        stk.pop_back();
        helper(n, pos + 1, k, stk, rst);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rst;
        if(k > n) return rst;
        vector<int> stk;
        helper(n, 1, k, stk, rst);
        return rst;
    }
};