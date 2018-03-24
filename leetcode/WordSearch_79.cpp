class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string str) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        if(visited[x][y]) return false;
        if(board[x][y] != str[0]) return false;
        if(str.size() == 1) return true;
        visited[x][y] = true;
        if(dfs(board, visited, x + 1, y, str.substr(1))) return true;
        if(dfs(board, visited, x, y + 1, str.substr(1))) return true;
        if(dfs(board, visited, x - 1, y, str.substr(1))) return true;
        if(dfs(board, visited, x, y - 1, str.substr(1))) return true;
        visited[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int hei = board.size();
        if(!hei) return false;
        int wid = board[0].size();
        if(!wid) return false;
        vector<vector<bool>> visited(hei, vector<bool>(wid, false));
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(dfs(board, visited, i, j, word)) return true;
        return false;
    }
};