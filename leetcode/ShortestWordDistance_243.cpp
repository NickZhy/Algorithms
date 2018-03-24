class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int lastPos1 = -1, lastPos2 = -1;
        int minDist = INT_MAX;
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                if(lastPos2 >= 0)
                    minDist = min(minDist, i - lastPos2);
                lastPos1 = i;
            }
            if(words[i] == word2) {
                if(lastPos1 >= 0)
                    minDist = min(minDist, i - lastPos1);
                lastPos2 = i;
            }
        }
        return minDist;
    }
};