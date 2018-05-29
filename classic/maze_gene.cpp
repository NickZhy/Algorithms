#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <unordered_set>

using namespace std;

/*
    0123456
  0 xxxxxxx
  1 x x x x
  2 xxxxxxx
  3 x x x x
  4 xxxxxxx
  5 x x x x
  6 xxxxxxx
  

*/

int find(int e, vector<int>& p) {
  if(p[e] != e) 
    p[e] = find(p[e], p);
  return p[e];
}

bool join(int a, int b, vector<int>& p, vector<int>& rank) { 
  int A = find(a, p);
  int B = find(b, p);
  if(A == B) return false;
  if(rank[A] < rank[B]) {
    p[B] = A;
  } else if (rank[B] > rank[A]) {
    p[A] = B;
  } else {
    ++rank[A];
    p[B] = A;
  }
  return true;
}

template<typename T>
void shuffle(vector<T>& lst) {
  srand(time(0));
  for(int i = 1; i < lst.size(); ++i) 
    swap(lst[rand() % i], lst[i]);
}

vector<vector<int>> prim(int wid, int hei) {
  vector<int> rank(wid * hei, 0);
  vector<int> p(wid * hei, 0);
  for(int i = 0; i < wid * hei; ++i)
    p[i] = i;

  vector<vector<int>> edges;
  for(int i = 0; i < hei; ++i)
    for(int j = 0; j < wid; ++j) {
      if(j + 1 < wid)
        edges.push_back({i * wid + j, i * wid + j + 1});
      if(i + 1 < hei)
        edges.push_back({i * wid + j, (i + 1) * wid + j});
    }
  shuffle<vector<int>>(edges);
  vector<vector<int>> ret(hei * 2 + 1, vector<int>(wid * 2 + 1, 0));
  for(auto e: edges) {
    if(!join(e[0], e[1], p, rank)) {
      int h = 1 + (e[0] / wid) + (e[1] / wid);
      int w = 1 + (e[0] % wid) + (e[1] % wid);
      ret[h][w] = 1;
    }
  }
  for(int i = 0; i < hei * 2 + 1; ++i) {
    ret[i][0] = 1;
    ret[i][wid * 2] = 1;
  }

  for(int i = 0; i < wid * 2 + 1; ++i) {
    ret[0][i] = 1;
    ret[hei * 2][i] = 1;
  }

  for(int i = 0; i < hei; ++i)
    for(int j = 0; j < wid; ++j)
      ret[i * 2][j * 2] = 1;

  return ret;
}

int main() {
  auto mp = prim(20, 20);
  for(auto col: mp) {
    for(auto e: col)
      cout << (e? 'X' : ' ') << " ";
    cout << endl;
  }
  return 0;
}
