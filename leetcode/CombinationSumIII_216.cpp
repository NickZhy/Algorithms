class Solution {
    void dfs(int k, int n, vector<int>& curr, vector<vector<int>>& rst) {
        if(k == 0) {
            if(n == 0)
                rst.push_back(curr);
            return;
        }
        int start = 1 + (curr.size()? curr.back(): 0); 
        for(int i = start; i < 10; ++i) {
            curr.push_back(i);
            dfs(k - 1, n - i, curr, rst);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> rst;
        vector<int> curr;
        dfs(k, n, curr, rst);
        return rst;
    }
};