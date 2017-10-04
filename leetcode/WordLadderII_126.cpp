typedef pair<string, int> entry;
class Solution {
public:
    vector<string> path;
    vector<vector<string>> rst;
    unordered_map<string, vector<string>> ancestor;
    
    bool connect(string& str1, string& str2) {
        int diff = 0;
        for(int i=0; i < str1.size(); ++i) {
            if(str1[i] != str2[i] && ++diff > 1)
                return false;
        }
        return diff == 1;
    }
    
    void bfs(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> visited;
        queue<entry> que;
        que.push(entry(beginWord, 0));
        visited[beginWord] = -1;
        bool findAns = false;
        while(que.size()) {
            entry cur = que.front();
            que.pop();
            
            if(cur.first.compare(endWord) == 0)
                break;

            for(auto word: wordList) {
                if(connect(word, cur.first)) {
                    if(visited[word] == 0) {
                        que.push(entry(word, cur.second + 1));
                        visited[word] = cur.second + 1;
                        ancestor[word].push_back(cur.first);
                    } else if(visited[word] == cur.second + 1) {
                        ancestor[word].push_back(cur.first);
                    }
                }
            }
        }
    }
    
    void dfs(string& beginWord, string& word) {
        if(word.compare(beginWord) == 0) {
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            rst.push_back(tmp);
        } else {
            for(auto anc: ancestor[word]) {
                path.push_back(anc);
                dfs(beginWord, anc);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bfs(beginWord, endWord, wordList);
        path.push_back(endWord);
        dfs(beginWord, endWord);
        return rst;
    }
    
};
