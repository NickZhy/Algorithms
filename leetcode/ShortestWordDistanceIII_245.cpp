class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < words.size(); ++i) mp[words[i]].push_back(i);
        int minLen = INT_MAX;
        if(word1 == word2) {
            vector<int>& l = mp[word1];
            for(int i = 1; i < l.size(); ++i)
                minLen = min(minLen, l[i] - l[i - 1]);
        } else {
            vector<int>& l = mp[word1];
            vector<int>& r = mp[word2];
            int i1 = 0, i2 = 0;
            while(i1 < l.size() && i2 < r.size()) {
                minLen = min(minLen, abs(l[i1] - r[i2]));
                if(l[i1] < r[i2]) 
                    ++i1;
                else 
                    ++i2;
            }
        }
        return minLen;
    }
};