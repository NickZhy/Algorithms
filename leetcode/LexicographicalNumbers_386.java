class Solution {
    void helper(List<Integer> rst, int curr, int n) {
        if(curr > n) return;
        rst.add(curr);
        helper(rst, curr * 10, n);
        if(curr % 10 != 9) helper(rst, curr + 1, n);
    }
    public List<Integer> lexicalOrder(int n) {
        List<Integer> rst = new ArrayList<Integer>();
        helper(rst, 1, n);
        return rst;
    }
}