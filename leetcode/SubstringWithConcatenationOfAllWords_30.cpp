// Solution one, violent search.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordCount;
        for(string word: words)
            ++wordCount[word];
     
        int wLen = words[0].size();
        int wNum = words.size();
        vector<int> result;
        for(int i = 0; i < s.size() - wNum * wLen + 1; ++i) {
            unordered_map<string, int> foundWord;
            bool hasFailed = false;
            for(int j = 0; !hasFailed && j < wNum * wLen; j += wLen) {
                string t = s.substr(i + j, wLen);
                if(foundWord[t] < wordCount[t])
                    foundWord[t]++;
                else
                    hasFailed = true;
            }
            if(!hasFailed)
                result.push_back(i);
        }
        return result;
    }
};

// Solution two, sliding window search. time complexity is O(N * wLen), considering map a string takes O(len(str)).
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordCount;
        for(string word: words)
            ++wordCount[word];
        
        int wLen = words[0].size();
        int wNum = words.size();
        int sLen = s.size();
        vector<int> result;
        for(int i = 0; i < wLen; ++i) {
            unordered_map<string, int> foundWord;
            int start = i;
            for(int j = i; j <= sLen - wLen;  j += wLen) {
                string t = s.substr(j, wLen);
                foundWord[t]++;
                while(foundWord[t] > wordCount[t]) {
                    string t2 = s.substr(start, wLen);
                    foundWord[t2]--;
                    start += wLen;
                }
                if(j - start == wLen * (wNum - 1)) {
                    result.push_back(start);
                }
            }
        }
        return result;
    }
};
