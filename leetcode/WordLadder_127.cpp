typedef pair<string, int> pr;
class Solution {
public:
    bool isConn(string str1, string str2) {
        int i = 0;
        while(i < str1.size() && str1[i] == str2[i]) ++i;
        if(i == str1.size()) return false;
        return str1.substr(i + 1) == str2.substr(i + 1);
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pr> qe;
        unordered_set<string> unvisited;
        for(string wd: wordList)
            unvisited.insert(wd);
        
        qe.push(pr(beginWord, 1));
        while(qe.size()) {
            pr curr = qe.front();
            qe.pop();
            auto it = unvisited.begin();
            while(it != unvisited.end()) {
                string wd = *it;
                if(!isConn(wd, curr.first)) {
                    ++it;
                } else {
                    if(wd == endWord)
                        return curr.second + 1;
                    qe.push(pr(wd, curr.second + 1));
                    it = unvisited.erase(it);
                }
            }
        }
        return 0;
    }
};
