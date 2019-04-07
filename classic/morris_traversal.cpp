#include <iostream>

using namespace std;

class Node {
  public:
  int val;
  int visitCount;
  Node* left;
  Node* right;
  Node(int v): val(v), visitCount(0), left(), right() {};
  ~Node() {
    if(left) delete left;
    if(right) delete right;
  }
};

Node* buildTree(int* a, int i, int j) {
  if(i > j) return NULL;
  int mid = (i + j) / 2;
  Node* root = new Node(a[mid]);
  root -> left = buildTree(a, i, mid - 1);
  root -> right = buildTree(a, mid + 1, j);
  return root;
}

// Space complexity O(1)
// Time complexity O(n) -> Each node can be visited at most 4 times, 
// in which 2 times are traversing and the other 2 times are searching 
// for precessor.

void morrisTraversal(Node* root) {
  Node* curr = root;
  while(curr) {
    ++curr -> visitCount;
    bool visit = false;
    if(!curr -> left) {
      visit = true;
    } else {
      Node* tmp = curr -> left;
      while(tmp -> right && tmp -> right != curr) {
        ++tmp -> visitCount;
        tmp = tmp -> right;
      }
      if(tmp -> right == curr) {
        tmp -> right = NULL;
        visit = true;
      } else {
        tmp -> right = curr;
        curr = curr -> left;
      }
    }
    if(visit) {
      //do whatever
      cout << curr -> val << " ";
      curr = curr -> right;
    }
  }
  cout << endl;
}

void dfs(Node* root) {
  if(!root) return;
  dfs(root -> left);
  cout << "Node " << root -> val << " : " << root -> visitCount << " | ";
  dfs(root -> right);
}

int main() {
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int len = *(&nums + 1) - nums;
  Node* root = buildTree(nums, 0, len - 1);
  morrisTraversal(root);
  dfs(root);
  cout << endl;
  return 0;
}
