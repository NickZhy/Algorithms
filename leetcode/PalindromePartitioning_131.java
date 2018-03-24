class Solution {
    static boolean isPalindrome(String s, int start, int end) {
        while(start < end)
            if(s.charAt(start++) != s.charAt(end--)) return false;
        return true;
    }
    void helper(String s, List<List<String>> rst, List<String> curr, int start) {
        if(start == s.length()) {
            rst.add(new ArrayList<String>(curr));
            return;
        }
        for(int i = start; i < s.length(); ++i) {
            if(isPalindrome(s, start, i)) {
                curr.add(s.substring(start, i + 1));
                helper(s, rst, curr, i + 1);
                curr.remove(curr.size() - 1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> rst = new ArrayList<List<String>>();
        List<String> curr = new ArrayList<String>();
        helper(s, rst, curr, 0);
        return rst;
    }
}