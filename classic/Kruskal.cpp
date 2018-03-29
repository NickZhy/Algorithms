#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  vector<int> ele;
  vector<int> rank;
  public:
  DisjointSet(int n): ele(n), rank(n, 0) {
    for(int i = 0; i < n; ++i)
      ele[i] = i;
  }

  int find(int i) {
    if(ele[i] != i)
      ele[i] = find(ele[i]);
    return ele[i];
  }

  bool join(int i, int j) {
    int iR = find(i), jR = find(j);
    if(iR == jR) return false;
    if(rank[iR] > rank[jR]) {
      ele[jR] = iR;
    } else if(rank[iR] < rank[jR]) {
      ele[iR] = jR;
    } else {
      ele[iR] = jR;
      ++rank[jR];
    }
    return true;
  }
};

// edge: [source, destiny, value]
vector<vector<int> > Kruskal(int n, vector<vector<int> >& edges) {
  vector<vector<int> > ret;
  DisjointSet ds(n);
  sort(edges.begin(), edges.end(), [](vector<int> a, vector<int> b) { return a[2] < b[2];});
  for(vector<int>& e: edges) {
    if(!ds.join(e[0], e[1])) continue;
    ret.push_back(e);
    if(ret.size() == n - 1) break;
  }
  return ret;
}

int main() {
  vector<vector<int> > edges = { {0, 1, 7}, {0, 3, 5}, 
                                {1, 2, 8}, {1, 3, 9}, {1, 4, 7},
                                {2, 4, 5},
                                {3, 4, 15}, {3, 5, 6},
                                {4, 5, 8}, {4, 6, 9},
                                {5, 6, 11}};
  vector<vector<int> > tree = Kruskal(7, edges);

  for(vector<int>& e: tree)
    cout << e[0] << "->" << e[1] << " : " << e[2] << endl;
  return 0;
}
