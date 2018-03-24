class NumArray {
public:
    class Node {
        public:
        int left;
        int right;
        int val;
        Node* lChild;
        Node* rChild;
        Node(int l, int r, int v) {
            lChild = rChild = NULL;
            left = l;
            right = r;
            val = v;
        }
    };
    
    Node* buildTree(vector<int>& nums, int i, int j) {
        if(i == j) return new Node(i, j, nums[i]);
        int mid = (i + j) / 2;
        Node* l = buildTree(nums, i , mid);
        Node* r = buildTree(nums, mid + 1, j);
        Node* root = new Node(i, j, l -> val + r -> val);
        root -> lChild = l;
        root -> rChild = r;
        return root;
    }
    
    int search(Node* root, int i, int j) {
        if(!root) return 0;
        int left = root -> left, right = root -> right;
        if(j < left || right < i) return 0; // no intersection
        if(i <= left && right <= j) return root -> val; // contains
        return search(root -> lChild, i, j) + search(root -> rChild, i, j);
    }
    
    int updateTree(Node* root, int i, int newVal) {
        if(!root) return 0;
        int left = root -> left, right = root -> right;
        if(i < left || right < i) return 0;
        int change = 0;
        if(root -> lChild) { // this node must have two children.
            change = updateTree(root -> lChild, i, newVal) + updateTree(root -> rChild, i, newVal);
        } else { // this is the leaf having the range [i, i];
            assert(left == right && i == left);
            change = newVal - root -> val;
        }
        root -> val += change;
        return change;
    }
    
    Node* segTree;
    
    NumArray(vector<int> nums) {
        int len = nums.size();
        if(len == 0) {
            segTree = NULL;
        } else {
            segTree = buildTree(nums, 0, len - 1);
        }
    }
    
    void update(int i, int val) {
        updateTree(segTree, i, val);
    }
    
    int sumRange(int i, int j) {
        return search(segTree, i, j);
    }
};

// struct SegmentTreeNode {
//     int start, end, sum;
//     SegmentTreeNode* left;
//     SegmentTreeNode* right;
//     SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
// };
// class NumArray {
//     SegmentTreeNode* root;
// public:
//     NumArray(vector<int> nums) {
//         int n = nums.size();
//         root = buildTree(nums,0,n-1);
//     }
   
//     void update(int i, int val) {
//         modifyTree(i,val,root);
//     }

//     int sumRange(int i, int j) {
//         return queryTree(i, j, root);
//     }
//     SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
//         if(start > end) return nullptr;
//         SegmentTreeNode* root = new SegmentTreeNode(start,end);
//         if(start == end) {
//             root->sum = nums[start];
//             return root;
//         }
//         int mid = start + (end - start) / 2;
//         root->left = buildTree(nums,start,mid);
//         root->right = buildTree(nums,mid+1,end);
//         root->sum = root->left->sum + root->right->sum;
//         return root;
//     }
//     int modifyTree(int i, int val, SegmentTreeNode* root) {
//         if(root == nullptr) return 0;
//         int diff;
//         if(root->start == i && root->end == i) {
//             diff = val - root->sum;
//             root->sum = val;
//             return diff;
//         }
//         int mid = (root->start + root->end) / 2;
//         if(i > mid) {
//             diff = modifyTree(i,val,root->right);
//         } else {
//             diff = modifyTree(i,val,root->left);
//         }
//         root->sum = root->sum + diff;
//         return diff;
//     }
//     int queryTree(int i, int j, SegmentTreeNode* root) {
//         if(root == nullptr) return 0;
//         if(root->start == i && root->end == j) return root->sum;
//         int mid = (root->start + root->end) / 2;
//         if(i > mid) return queryTree(i,j,root->right);
//         if(j <= mid) return queryTree(i,j,root->left);
//         return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
//     }
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */