class Solution {
    
    boolean sameChar(String s1, String s2) {
        int count[] = new int[256];
        for(char ch: s1.toCharArray())
            count[ch]++;
        for(char ch: s2.toCharArray()) {
            count[ch]--;
            if(count[ch] < 0) return false;
        }
        return true;
    }
    
    public boolean isScramble(String s1, String s2) {
        if(s1.compareTo(s2) == 0) return true;
        int len = s1.length();
        if(!sameChar(s1, s2)) return false;
        for(int i = 1; i < len; ++i) {
            int headLen = i;
            int tailLen = len - i;
            String head = s1.substring(0, headLen);
            String tail = s1.substring(headLen);
            if(isScramble(head, s2.substring(0, headLen)) && isScramble(tail, s2.substring(headLen))) return true;
            if(isScramble(tail, s2.substring(0, tailLen)) && isScramble(head, s2.substring(tailLen))) return true;
        }
        return false;
        
    }
}