class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int idx = 0;
        while(idx < s.size()) {
            while(idx < s.size() && s[idx] == ' ') ++idx;
            count += idx < s.size();
            while(idx < s.size() && s[idx] != ' ') ++idx;
        }
        return count;
    }
};