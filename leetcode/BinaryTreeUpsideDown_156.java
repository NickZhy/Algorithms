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
    class TreeInfo {
        TreeNode root;
        TreeNode rightLeaf;
        TreeInfo(TreeNode r, TreeNode rLeaf) {
            root = r;
            rightLeaf = rLeaf;
        }
    }
    
    TreeInfo helper(TreeNode root) {
        if(root == null) return new TreeInfo(null, null);
        if(root.left == null) {
            TreeNode node = new TreeNode(root.val);
            return new TreeInfo(node, node);
        }
        TreeInfo l = helper(root.left);
        TreeInfo r = helper(root.right);
        TreeNode rightLeaf = l.rightLeaf;
        rightLeaf.right = new TreeNode(root.val);
        rightLeaf.left = r.root;
        return new TreeInfo(l.root, rightLeaf.right);
    }
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        TreeInfo rst = helper(root);
        return rst.root;
    }
}