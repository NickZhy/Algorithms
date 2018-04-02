#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../visualize/visualize.hpp"
using namespace std;

class Node: public BinTreeNode {
  public:
  int val, height;
  Node *left, *right;
  Node(int v): val(v), height(1), left(NULL), right(NULL) {}
  ~Node() {
    if(!left) delete left;
    if(!right) delete right;
  }

  BinTreeNode* lCh() {
    return left;
  }

  BinTreeNode* rCh() {
    return right;
  }

  string info() const {
    return "(" + to_string(val) + "," + to_string(height) + ")";
  }

};

int updateHei(Node* root) {
  int l = root -> left? root -> left -> height: 0;
  int r = root -> right? root -> right -> height: 0;
  root -> height = max(l, r) + 1;
  return l - r;
}

Node* rotateLL(Node* root) {
  Node* l = root -> left;
  root -> left = l -> right;
  l -> right = root;
  updateHei(root);
  updateHei(l);
  return l;
}

Node* rotateRR(Node* root) {
  Node* r = root -> right;
  root -> right = r -> left;
  r -> left = root;
  updateHei(root);
  updateHei(r);
  return r;
}

Node* rotateLR(Node* root) {
  root -> left = rotateRR(root -> left);
  return rotateLL(root);
}

Node* rotateRL(Node* root) {
  root -> right = rotateLL(root -> right);
  return rotateRR(root);
}

Node* balance(Node* root) {
  int hdiff = updateHei(root);
  if(abs(hdiff) < 2) return root;
  if(hdiff > 0) {
    if(updateHei(root -> left) >= 0)
      return rotateLL(root);
    return rotateLR(root);
  }
  if(updateHei(root -> right) <= 0)
    return rotateRR(root);
  return rotateRL(root);
}

Node* insert(Node* root, int val) {
  if(!root) return new Node(val);
  if(val < root -> val)
    root -> left = insert(root -> left, val);
  else
    root -> right = insert(root -> right, val);
  return balance(root);
}

Node* erase(Node* root, int val) {
  if(!root) return NULL;
  if(val < root -> val) {
    root -> left = erase(root -> left, val);
  } else if(val > root -> val) {
    root -> right = erase(root -> right, val);
  } else {
    if(!root -> left) {
      Node* ret = root -> right;
      root -> right = NULL;
      delete(root);
      return ret;
    }
    if(!root -> right) {
      Node* ret = root -> left;
      root -> left = NULL;
      delete(root);
      return ret;
    }
    Node* succ = root -> right;
    while(succ -> left)
      succ = succ -> left;
    swap(succ -> val, root -> val);
    root -> right = erase(root -> right, val);
  }
  return balance(root);
}

vector<int> perm(int s, int e) {
  if(e < s) return {};
  vector<int> ret;
  for(int i = 0; i < e - s + 1; ++i) {
    ret.push_back(i + s);;
    swap(ret[i], ret[rand() % (i + 1)]);
  }
  return ret;
}

int main() {
  vector<int> nums = perm(0, 20);
  for(int n: nums)
    cout << n << " ";
  cout << endl;

  Node* root = NULL;
  for(int n: nums) {
    cout << "------insert:------" << n << endl << endl;
    root = insert(root, n);
    showBinTree(root);
  }
  for(int n: nums) {
    cout << "------delete:------" << n << endl << endl;
    root = erase(root, n);
    showBinTree(root);
  }
  return 0;
}

