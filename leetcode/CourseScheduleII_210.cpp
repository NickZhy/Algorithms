class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, int n, vector<int>& visited, vector<int>& rst) {
        if(visited[n] == 1) return false;
        if(visited[n] == 2) return true;
        
        visited[n] = 1;
        for(int prev: graph[n]) 
            if(!dfs(graph, prev, visited, rst)) return false;
        visited[n] = 2;
        rst.push_back(n);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<bool> isPreq(numCourses, false);
        for(pair<int, int> pre: prerequisites) {
            graph[pre.first].push_back(pre.second);
            isPreq[pre.second] = true;
        }
        vector<int> visited(numCourses, 0), rst;
        for(int i = 0; i < numCourses; ++i) {
            if(!isPreq[i]) {
                if(!dfs(graph, i, visited, rst)) 
                    return vector<int>();
            }
        }
        for(int i = 0; i < numCourses; ++i)
            if(!visited[i]) return vector<int>();
        return rst;
    }
};