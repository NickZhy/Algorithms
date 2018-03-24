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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;
        if(key < root.val) {
            root.left = deleteNode(root.left, key);
        } else if(key > root.val) {
            root.right = deleteNode(root.right, key);
        } else {
            if(root.right == null) return root.left;
            if(root.left == null) return root.right;
            
            TreeNode next = root.right;
            TreeNode last = null;
            while(next.left != null) {
                last = next;
                next = next.left;
            }
            root.val = next.val;
            if(last == null)
                root.right = next.right;
            else
                last.left = next.right;
        }
        return root;
    }
}