class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if(!len || !n) return len;
        int count[26] = { 0 };
        int maxLen = 0;
        for(char t: tasks) {
            ++count[t - 'A'];
            maxLen = max(maxLen, count[t - 'A']);
        }
        int maxCount = 0;
        for(int i = 0; i < 26; ++i)
            if(count[i] == maxLen) ++maxCount;
        return max((maxLen - 1) * (n + 1) + maxCount, len);
    }
};