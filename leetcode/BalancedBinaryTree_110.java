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
    class Pair {
        int height;
        boolean balance;
        public Pair(int h, boolean b) {
            height = h;
            balance = b;
        }
    }
    Pair dfs(TreeNode root) {
        if(root == null) return new Pair(0, true);
        Pair l = dfs(root.left);
        if(!l.balance) return new Pair(0, false);
        Pair r = dfs(root.right);
        if(!r.balance || Math.abs(l.height - r.height) > 1) return new Pair(0, false);
        return new Pair(Math.max(l.height, r.height) + 1, true);
    }
    public boolean isBalanced(TreeNode root) {
        Pair p = dfs(root);
        return p.balance;
    }
}