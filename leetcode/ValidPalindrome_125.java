class Solution {
    int getChar(char c) {
        if(c >= 'A' && c <= 'Z')
            return c - 'A';
        if(c >= 'a' && c <= 'z')
            return c - 'a';
        if(c >= '0' && c <= '9')
            return c - '0' + 26;
        return -1;
    }
    public boolean isPalindrome(String s) {
        int start = 0, end = s.length() - 1;
        while(start < end) {
            int ch1 = getChar(s.charAt(start));
            int ch2 = getChar(s.charAt(end));
            if(ch1 < 0) ++start;
            if(ch2 < 0) --end;
            if(ch1 >= 0 && ch2 >= 0) {
                if(ch1 != ch2) 
                    return false;
                ++start;
                --end;
            }
        }
        return true;
    }
}