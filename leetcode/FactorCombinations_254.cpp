class Solution {
public:
    void helper(int n, vector<int>& curr, vector<vector<int>>& rst) {
        if(curr.size() > 0) {
            curr.push_back(n);
            rst.push_back(curr);
            curr.pop_back();
        }
        int start = curr.size() > 0? curr.back(): 2;
        for(int i = start; i <= sqrt(n); ++i) {
            if(n % i == 0) {
                curr.push_back(i);
                helper(n / i, curr, rst);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<int> curr;
        vector<vector<int>> rst;
        helper(n, curr, rst);
        return rst;
    }
};