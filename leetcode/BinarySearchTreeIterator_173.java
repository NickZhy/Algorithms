/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    Stack<TreeNode> stk;
    public BSTIterator(TreeNode root) {
        stk = new Stack<TreeNode>();
        while(root != null) {
            stk.push(root);
            root = root.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode curr = stk.pop();
        int rst = curr.val;
        curr = curr.right;
        while(curr != null) {
            stk.push(curr);
            curr = curr.left;
        }
        return rst;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */