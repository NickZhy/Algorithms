class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while(start < end)
            if(s[start++] != s[end--]) return false;
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while(start < end) {
            if(s[start] != s[end]) {
                return isPalindrome(s.substr(start, end - start)) || isPalindrome(s.substr(start + 1, end - start));
            }
            ++start;
            --end;
        }
        return true;
    }
};