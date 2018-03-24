class Solution {
    void dfs(int curr, int tar, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& rst) {
        path.push_back(curr);
        if(curr == tar) {
            rst.push_back(path);
            path.pop_back();
            return;
        }
        for(int n: graph[curr]) 
            dfs(n, tar, graph, path, rst);
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(!graph.size()) return {};
        vector<vector<int>> rst;
        vector<int> path;
        dfs(0, graph.size() - 1, graph, path, rst);
        return rst;
    }
};