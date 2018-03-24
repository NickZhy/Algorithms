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
    void dfs(TreeNode root, int depth, List<Integer> rst) {
        if(root == null) return;
        if(rst.size() == depth) rst.add(root.val);
        dfs(root.right, depth + 1, rst);
        dfs(root.left, depth + 1, rst);
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> rst = new ArrayList<Integer>();
        dfs(root, 0, rst);
        return rst;
    }
}