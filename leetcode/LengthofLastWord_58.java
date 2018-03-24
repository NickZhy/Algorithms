class Solution {
    public int lengthOfLastWord(String s) {
        int len = s.length();
        if(len == 0) return 0;
        int idx = s.length() - 1;
        while(idx >= 0 && s.charAt(idx) == ' ') --idx;
        int end = idx;
        while(idx >= 0 && s.charAt(idx) != ' ') --idx;
        return end - idx;
    }
}