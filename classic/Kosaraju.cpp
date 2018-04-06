#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/* The idea behind this algorihm is actually very simple. If we just do DFS from each node
 * and consider all reachable nodes as one SCC, unless we are lucky, in most cases it may 
 * contains more than one SCCs. To fix that, we preform a post-order DFS on reversed graph.
 * and repeat our "naive" method following the reversed post-order. 
 *
 * This time it is impossible to visit more than one SCC in each DFS. Assume we can visit SCC
 * B from A. The post-order DFS on reversed graph gurantees that all elements in B appears 
 * after all of elements in A. And since we scan reversely, we should have already visited B
 * when we visit A.
 */


void dfs(int curr, vector<int>& vec, unordered_set<int>& visited, vector<vector<int>>& graph) {
  if(visited.count(curr)) return;
  visited.insert(curr);
  for(int next: graph[curr])
    dfs(next, vec, visited, graph);
  vec.push_back(curr);
}

vector<vector<int>> Kosaraju(vector<vector<int>>& graph) {
  vector<vector<int>> revGraph(graph.size());
  int n = graph.size();
  for(int i = 0; i < n; ++i)
    for(int des: graph[i]) 
      revGraph[des].push_back(i);
  
  vector<int> postOrder;
  unordered_set<int> visited;
  for(int i = 0; i < n; ++i) {
    if(visited.count(i)) continue;
    dfs(i, postOrder, visited, revGraph);
  }
  
  vector<vector<int>> ret;
  reverse(postOrder.begin(), postOrder.end());

  visited.clear();
  for(int v: postOrder) {
    if(visited.count(v)) continue;
    vector<int> comp;
    dfs(v, comp, visited, graph);
    ret.push_back(comp);
  }
  return ret;
}

int main() {
  vector<vector<int>> graph = {
    {3, 2}, // node 0
    {0}, // node 1
    {1}, // node 2
    {4}, // node 3
    {}   // node 4
  };

  vector<vector<int>> comps = Kosaraju(graph);
  for(auto cp: comps) {
    for(auto ele: cp)
      cout << ele << " ";
    cout << endl;
  }
  return 0;
}
