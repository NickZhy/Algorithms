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
    void dfs(TreeNode root, List<List<Integer>> rst, List<Integer> curr, int sum) {
        curr.add(root.val);
        if(root.val == sum && root.left == null && root.right == null) {
            rst.add(new ArrayList<Integer>(curr));
        }
        if(root.left != null) dfs(root.left, rst, curr, sum - root.val);
        if(root.right != null) dfs(root.right, rst, curr, sum - root.val);
        curr.remove(curr.size() - 1);
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> rst = new ArrayList<List<Integer>>();
        if(root == null) return rst;
        List<Integer> curr = new ArrayList<Integer>();
        dfs(root, rst, curr, sum);
        return rst;
    }
}