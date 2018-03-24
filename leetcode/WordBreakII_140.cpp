class Solution {
public:
    class TrieNode {
        public:
        bool hasWord;
        TrieNode* child[26];
        TrieNode():child(), hasWord(false) { }
        ~TrieNode() {
            for(int i = 0; i < 26; ++i)
                if(child[i]) delete child[i];
        }
    };

    void addWord(TrieNode* root, string& s) {
        TrieNode* curr = root;
        for(char ch: s) {
            int idx = ch - 'a';
            if(!curr -> child[idx]) curr -> child[idx] = new TrieNode();
            curr = curr -> child[idx];
        }
        curr -> hasWord = true;
    }
    
    void dfs(TrieNode* root, string& s, int idx, vector<string>& tRst, vector<string>& rst) {
        if(idx == s.size()) {
            string r = "";
            for(string s: tRst)
                r += s + " ";
            r.pop_back();
            rst.push_back(r);
        }
        
        TrieNode* curr = root;
        int len = 0;
        while(curr && idx + len < s.size()) {
            int t = s[idx + len] - 'a';
            curr = curr -> child[t];
            ++len;
            if(curr && curr -> hasWord) {
                tRst.push_back(s.substr(idx, len));
                dfs(root, s, idx + len, tRst, rst);
                tRst.pop_back();
            }
        }
    }
    bool check(string& s, vector<string>& wordDict) {
        unordered_set<char> hasChar;
        for(string wd: wordDict) {
            for(char ch: wd)
                hasChar.insert(ch);
        }
        for(char ch: s)
            if(hasChar.count(ch) == 0) return false;
        return true;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(!s.size() || !check(s, wordDict)) return vector<string>();

        TrieNode* root = new TrieNode();
        for(string& wd: wordDict) 
            addWord(root, wd);
        
        vector<string> rst, tRst;
        dfs(root, s, 0, tRst, rst);
        delete root;
        
        return rst;
    }
};