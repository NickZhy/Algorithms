class Solution {
    int hashChar(char ch) {
        if(ch <= 'Z') return ch - 'A';
        return 26 + ch - 'a';
    }
    int numOfCh(int count[]) {
        int rst = 0;
        for(int i = 0; i < 52; ++i) {
            if(count[i] > 0) ++rst;
        }
        return rst;
    }
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int count[] = new int[52];
        int start = 0, end = 0;
        int maxLen = 0;
        while(end < s.length()) {
            while(end < s.length() && numOfCh(count) <= 2)  ++count[hashChar(s.charAt(end++))];
            maxLen = Math.max(maxLen, end - start - 1);
            while(numOfCh(count) > 2) --count[hashChar(s.charAt(start++))];
        }
        maxLen = Math.max(maxLen, end - start);
        return maxLen;
    }
}