typedef pair<int, int> pr;
class Solution {
    class Node {
        public:
        string* word;
        unordered_map<char, Node*> child;
        Node() {
            word = NULL;
        }
    };
    
    static void insert(Node *root, string* s) {
        for(char ch: *s) {
            if(!root -> child.count(ch))
                root -> child[ch] = new Node();
            root = root -> child[ch];
        }
        root -> word = s;
    }
    
public:
    int n,m;
    unordered_set<string> rst;
    
    void find(vector<vector<char>>& board, int i, int j, Node* root, vector<vector<bool>> visited) {
        if(i < 0 || i >=n || j < 0 || j >= m ) return;
        if(!root -> child.count(board[i][j])) return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        
        root = root -> child[board[i][j]];
        if(root -> word)
            rst.insert(*root -> word);
        
        find(board, i - 1, j, root, visited);
        find(board, i, j - 1, root, visited);
        find(board, i + 1, j, root, visited);
        find(board, i, j + 1, root, visited);
        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        n = board.size();
        if(!n) return result;
        m = board[0].size();
        if(!m) return result;
        
        Node* root = new Node();
        for(int i = 0; i < words.size(); ++i)
            insert(root, &words[i]);
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                find(board, i, j, root, visited);
        
        for(string wd: rst) 
            result.push_back(wd);
        return result;
    }
};
