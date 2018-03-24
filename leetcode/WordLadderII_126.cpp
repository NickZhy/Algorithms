class Solution {
public:
    void dfs(string wd, vector<string>& curr, unordered_map<string, vector<string>>& parents, vector<vector<string>>& rst) {
        if(!parents.count(wd)) {
            rst.push_back(curr);
            return;
        }
        for(string p: parents[wd]) {
            curr.push_back(p);
            dfs(p, curr, parents, rst);
            curr.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(string& wd: wordList) dict.insert(wd);
        if(!dict.count(endWord)) return vector<vector<string>>();
        
        queue<string> q;
        unordered_map<string, int> visited;
        unordered_map<string, vector<string>> parents;
        q.push(beginWord);
        visited[beginWord] = 0;
        while(q.size()) {
            string curr = q.front();
            q.pop();
            if(curr == endWord) break;
            int depth = visited[curr];
            for(int i = 0; i < curr.size(); ++i)
                for(char c = 'a'; c <= 'z'; ++c) {
                    if(c == curr[i]) continue;
                    string tmp = curr;
                    tmp[i] = c;
                    if(dict.count(tmp)) {
                        if(!visited.count(tmp)) {
                            visited[tmp] = depth + 1;
                            q.push(tmp);
                        } 
                        if(depth < visited[tmp])
                            parents[tmp].push_back(curr);
                    }
                    
                }
        }
        vector<vector<string>> rst;
        if(!parents.count(endWord)) return rst;
        vector<string> curr;
        curr.push_back(endWord);
        dfs(endWord, curr, parents, rst);
        for(vector<string>& r: rst) reverse(r.begin(), r.end());
        return rst;
    }
};