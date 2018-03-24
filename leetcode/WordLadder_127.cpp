typedef pair<string, int> pr;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(string& wd: wordList) dict.insert(wd);
        if(!dict.count(endWord)) return 0;
        
        queue<pr> que;
        que.push(pr(beginWord, 1));
        dict.erase(beginWord);
        while(que.size()) {
            pr curr = que.front();
            que.pop();
            string& str = curr.first;
            int& dep = curr.second;
            for(int i = 0; i < str.size(); ++i) {
                string tmp = str;
                for(char j = 'a'; j <= 'z'; ++j) {
                    tmp[i] = j;
                    if(tmp == endWord) return dep + 1;
                    if(dict.count(tmp)) {
                        que.push(pr(tmp, dep + 1));
                        dict.erase(tmp);
                    }
                }
            }
        }
        return 0;
    }
};