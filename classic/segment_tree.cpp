#include <iostream>
#include <vector>
using namespace std;

//segment tree to solve range sum problem

class Node {
  public:
  int val;
  int lower, upper;
  Node* left, *right;
  Node(int low, int up): val(0), lower(low), upper(up), left(), right() {}
};

Node* buildTree(vector<int>& nums, int i, int j) {
  if(i > j) return NULL;

  Node* root = new Node(i, j);
  if(i < j) {
    int mid = (i + j) / 2;
    root -> left = buildTree(nums, i, mid);
    root -> right = buildTree(nums, mid + 1, j);
    root -> val = root -> left -> val + root -> right -> val;
  } else{
    root -> val = nums[i];
  }
  return root;
}

int search(Node* root, int i, int j) {
  if(!root) return 0;
  int lower = root -> lower, upper = root -> upper;
  if(j < lower || upper < i) return 0;
  if(i <= lower && upper <= j) return root -> val;
  return search(root -> left, i, j) + search(root -> right, i, j);
}

void update(Node* root, int i, int val) {
  if(!root) return;
  int lower = root -> lower, upper = root -> upper;
  if(i < lower || upper < i ) return;
  if(lower == upper && lower == i) {
    root -> val = val;
    return;
  }
  update(root -> left, i, val);
  update(root -> right, i, val);
  root -> val = root -> left -> val + root -> right -> val;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
  Node* root = buildTree(nums, 0, nums.size() - 1);
  cout << "[0, 3] " << search(root, 0, 3) << ", [4, 5] " << search(root, 4, 5) << endl;
  update(root, 2, 9);
  cout << "[0, 3] " << search(root, 0, 3) << ", [4, 5] " << search(root, 4, 5) << endl;
  update(root, 4, 0);
  cout << "[0, 3] " << search(root, 0, 3) << ", [4, 5] " << search(root, 4, 5) << endl;
  return 0;
}
