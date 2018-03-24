class Solution {
public:
    void reverseSeg(vector<char>& str, int start, int end) {
        while(start < end) swap(str[start++], str[end--]);
    }
    void reverseWords(vector<char>& str) {
        int len = str.size();
        if(!len) return;
        reverseSeg(str, 0, len - 1);
        int start = 0, end = 0;
        while(end < len) {
            while(end < len && str[end] != ' ') ++end;
            reverseSeg(str, start, end - 1);
            start = ++end;
        }
    }
};