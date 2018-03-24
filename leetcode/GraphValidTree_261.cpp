class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, int node, vector<bool>& visited) {
        if(visited[node]) return;
        visited[node] = true;
        for(int n: graph[node])
            dfs(graph, n, visited);
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n - 1) return false;
        unordered_map<int, vector<int>> graph;
        for(pair<int, int> e: edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        dfs(graph, 0, visited);
        for(bool v: visited)
            if(!v) return false;
        return true;
    }
};