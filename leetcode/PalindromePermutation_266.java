class Solution {
    public boolean canPermutePalindrome(String s) {
        int count[] = new int[256];
        for(char ch: s.toCharArray())
            ++count[ch];
        boolean hasOne = false;
        for(int i = 0; i < 256; ++i) {
            if(count[i] % 2 == 1) {
                if(hasOne) return false;
                hasOne = true;
            }
        }
        return true;
    }
}