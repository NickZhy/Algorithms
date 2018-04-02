#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// this version support range update, and is more suitable for questions related to intervals.
class Node {
  public:
    int left, right, val;
    bool sign;
    Node *l, *r;
    Node(int lb, int rb): left(lb), right(rb) { 
      sign = true;
      val = 0;
      l = r = NULL;
    }
    ~Node() {
      if(l) delete l;
      if(r) delete r;
    }
};

// max val in the range. * vals are positive
int query(Node* root, int l, int r) {
  if(!root) return 0;
  if(r < root -> left || l > root -> right) return 0;
  if(root -> sign || (l <= root -> left && r >= root -> right)) return root -> val;
  return max(query(root -> l, l, r), query(root -> r, l, r));
}

// set all number in range to val
void update(Node* root, int l, int r, int val) {
  int left = root -> left, right = root -> right;
  if(!root || r < left || l > right) return;
  if(l <= left && r >= right) {
      root -> sign = true;
      root -> val = val;
      return;
  }
  if(root -> sign) {
      if(!root -> l) {
          int mid = left + (right - left) / 2;
          root -> l = new Node(left, mid);
          root -> r = new Node(mid + 1, right);
      }
      root -> l -> sign = root -> r -> sign = true;
      root -> l -> val = root -> r -> val = root -> val;
      root -> sign = false;
  }
  root -> val = val;
  update(root -> l, l, r, val);
  update(root -> r, l, r, val);
}

int main () {
  // interval (left, right, val)
  vector<vector<int>> interval = {{1, 2, 5}, {3, 4, 2}, {7, 10, 4}, {1, 20, 3}};
  Node* root = new Node(0, 30);
  for(auto inv: interval) {
    cout << "range: " << "(" << inv[0] << "," << inv[1] << ") val: " << query(root, inv[0], inv[1]) << endl;
    update(root, inv[0], inv[1], inv[2]);
  }
  delete root;
  return 0;
}
