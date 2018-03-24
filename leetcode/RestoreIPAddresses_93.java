class Solution {
    boolean isValid(String s) {
        if(s.length() > 3) return false;
        if(s.charAt(0) == '0' && s.length() > 1) return false;
        int i = Integer.parseInt(s);
        if(i > 255) return false;
        return true;
    }
    
    void helper(String s, int pos, int num, String curr, List<String> rst) {
        if(pos >= s.length()) {
            if(num == 4) 
                rst.add(curr);
            return;
        }
        if(num >= 4) return;
        String tmp = "";
        for(int i = pos; i < s.length(); ++i) {
            tmp += s.charAt(i);
            if(!isValid(tmp)) break;
            int initLen = curr.length();
            if(curr.length() > 0) curr += '.';
            curr += tmp;
            helper(s, i + 1, num + 1, curr, rst);
            curr = curr.substring(0, initLen);
        }
    }
    
    public List<String> restoreIpAddresses(String s) {
        List<String> rst = new ArrayList<String>();
        String curr = "";
        helper(s, 0, 0, curr, rst);
        return rst;
    }
}