/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    void dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& gMap) {
        if(!node || gMap.count(node)) return;
        gMap[node] = new UndirectedGraphNode(node -> label);
        for(auto nei: node -> neighbors) dfs(nei, gMap);
        for(auto nei: node -> neighbors) (gMap[node] -> neighbors).push_back(gMap[nei]);
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> gMap;
        dfs(node, gMap);
        return gMap[node];
    }
};