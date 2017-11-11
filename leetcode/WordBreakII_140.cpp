class Solution {
    class Node {
        public:
        bool hasWord;
        Node* children[26];
        Node() {
            hasWord = false;
            for(int i = 0; i < 26; ++i)
                children[i] = NULL;
        }
    };
    
    void insertWord(Node* root, string& wd) {
        for(char ch: wd) {
            int idx = ch - 'a';
            if(!root -> children[idx])
                root -> children[idx] = new Node();
            root = root -> children[idx];
        }
        root -> hasWord = true;
    }
    
    vector<int> searchAll(Node* root, string& s, int pos) {
        vector<int> rst;
        while(root && pos < s.size()) {
            int idx = s[pos++] - 'a';
            root = root -> children[idx];
            if(root && root -> hasWord)
                rst.push_back(pos);
        }
        return rst;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Node* root = new Node();
        for(string wd: wordDict)
            insertWord(root, wd);
        
        //DFS, find all possible words.
        vector<vector<int>> traceback(s.size() + 1);
        vector<int> stk;
        unordered_set<int> visited;
        visited.insert(0);
        stk.push_back(0);
        while(stk.size()) {
            int pos = stk.back();
            stk.pop_back();
            vector<int> ends = searchAll(root, s, pos);
            for(int end: ends) {
                traceback[end].push_back(pos);
                if(!visited.count(end)) {
                    stk.push_back(end);
                    visited.insert(end);
                }
            }
        }
        
        //BFS, generate answer
        visited.clear();
        stk.push_back(s.size());
        vector<vector<string>> rst(s.size() + 1);
        rst[s.size()].push_back("");
        while(stk.size()) {
            // Here we need to make sure bigger position is visited before smaller position.
            pop_heap(stk.begin(), stk.end());
            int pos = stk.back();
            stk.pop_back();
            for(int start: traceback[pos]) {
                for(string r: rst[pos])
                    rst[start].push_back(s.substr(start, pos - start) + " " + r);
                
                if(!visited.count(start)) {
                    stk.push_back(start);
                    push_heap(stk.begin(), stk.end());
                    visited.insert(start);
                }
            }
            if(pos) rst[pos].clear(); // save memory
        }
        //remove extra space in the end
        for(int i = 0; i < rst[0].size(); ++i)
            rst[0][i] = rst[0][i].substr(0, rst[0][i].size() - 1);
        return rst[0];
    }
};
