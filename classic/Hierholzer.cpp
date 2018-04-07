#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, vector<int>& ret, vector<vector<int>>& graph) {
  while(graph[curr].size()) {
    int next = graph[curr].back();
    graph[curr].pop_back();
    dfs(next, ret, graph);
  }
  ret.push_back(curr);
}

vector<int> Hierholzer(vector<vector<int>>& graph) {
  vector<int> ret;
  dfs(0, ret, graph);

  return vector<int>(ret.rbegin(), ret.rend());
}

int main() {
  vector<vector<int>> graph = {
    {1, 6},
    {2},
    {0, 3},
    {4},
    {2, 5},
    {0},
    {4}
  };

  vector<int> EulerCircuit = Hierholzer(graph);

  for(int i = 0; i < EulerCircuit.size() - 1; ++i)
    cout << EulerCircuit[i] << " -> ";
  cout << EulerCircuit.back() << endl;
  return 0;
}
