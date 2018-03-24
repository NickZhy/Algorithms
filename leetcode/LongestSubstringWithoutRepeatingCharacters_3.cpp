class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int i = 0, j = 0, maxLen = 0;
        unordered_set<char> window;
        while(i < len && j < len) {
            while(j < len && !window.count(s[j]))
                window.insert(s[j++]);
            maxLen = max(maxLen, j - i);
            window.erase(s[i++]);
        }
        return maxLen;
    }
};