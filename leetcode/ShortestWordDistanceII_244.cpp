class WordDistance {
    unordered_map<string, vector<int>> mem;
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); ++i)
            mem[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int>& p1 = mem[word1];
        vector<int>& p2 = mem[word2];
        int i = 0, j = 0, minDist = INT_MAX;
        while(i < p1.size() && j < p2.size()) {
            minDist = min(minDist, abs(p1[i] - p2[j]));
            if(p1[i] < p2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */