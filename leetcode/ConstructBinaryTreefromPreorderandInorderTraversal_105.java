/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode subBuildTree(int[] preorder, int[] inorder, int s1, int e1, int s2, int e2) {
        if(s1 > e1 || s2 > e2) return null;
        int root = preorder[s1];
        int len = 0;
        while(s2 + len <= e2) {
            if(inorder[s2 + len] == root) break;
            ++len;
        }
        TreeNode rst = new TreeNode(root);
        rst.left = subBuildTree(preorder, inorder, s1 + 1, s1 + len, s2, s2 + len - 1);
        rst.right = subBuildTree(preorder, inorder, s1 + len + 1, e1, s2 + len + 1, e2);
        return rst;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return subBuildTree(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
    }
}