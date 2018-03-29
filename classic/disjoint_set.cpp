#include <iostream>
#include <vector>

using namespace std;

void init(vector<int>& ele) {
  for(int i = 0; i < ele.size(); ++i)
    ele[i] = i;
}

int find(vector<int>& ele, int i) {
  if(ele[i] != i)
    ele[i] = find(ele, ele[i]);
  return ele[i];
}

void unionSet(vector<int>& ele, vector<int>& rank, int i, int j) {
  int iRoot = find(ele, i);
  int jRoot = find(ele, j);
  if(iRoot == jRoot) return;
  if(rank[iRoot] < rank[jRoot]) {
    ele[iRoot] = jRoot;
  } else if(rank[iRoot] > rank[jRoot]){
    ele[jRoot] = iRoot;
  } else {
    ele[iRoot] = jRoot;
    ++rank[jRoot];
  }
}

int main() {
  int N = 20;
  vector<int> ele(N);
  vector<int> rank(N, 0);
  init(ele);
  unionSet(ele, rank, 5, 6);
  unionSet(ele, rank, 3, 5);
  cout << "find 3 " << find(ele, 3) << endl;
  cout << "find 5 " << find(ele, 5) << endl;
  return 0;
}
