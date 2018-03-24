class Solution {
    class Node {
        public:
        bool hasWord;
        Node* father;
        Node* child[26];
        char ch;
        Node(char c): ch(c), child(), father(), hasWord(false) {}
        ~Node() {
            for(int i = 0; i < 26; ++i) 
                if(child[i]) delete child[i];
        }
    };
    static void addWord(Node* root, string& word) {
        Node* curr = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(!curr -> child[idx]) {
                curr -> child[idx] = new Node(ch);
                curr -> child[idx] -> father = curr;
            }
            curr = curr -> child[idx];
        }
        curr -> hasWord = true;
    }
public:
    void dfs(Node* curr, int i, int j, vector<vector<char>>& board, unordered_set<Node*>& rst) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(board[i][j] == ' ') return;
        char ch = board[i][j];
        curr = curr -> child[ch - 'a'];
        if(!curr) return;
        if(curr -> hasWord) rst.insert(curr);
        board[i][j] = ' ';
        dfs(curr, i + 1, j, board, rst);
        dfs(curr, i, j + 1, board, rst);
        dfs(curr, i - 1, j, board, rst);
        dfs(curr, i, j - 1, board, rst);
        board[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node(' ');
        for(string& wd: words) addWord(root, wd);
        
        unordered_set<Node*> rst;
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                dfs(root, i, j, board, rst);
        vector<string> result;
        for(Node* n: rst) {
            string tmp = "";
            while(n -> father) {
                tmp += n -> ch;
                n = n -> father;
            }
            reverse(tmp.begin(), tmp.end());
            result.push_back(tmp);
        }
        return result;
    }
};