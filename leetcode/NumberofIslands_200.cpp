class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = true;
        dfs(i + 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i - 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int hei = grid.size();
        if(!hei) return 0;
        int wid = grid[0].size();
        if(!wid) return 0;
        vector<vector<bool>> visited(hei, vector<bool>(wid, false));
        int count = 0;
        for(int i = 0; i < hei; ++i)
            for(int j = 0; j < wid; ++j)
                if(!visited[i][j] && grid[i][j] == '1') {
                    ++count;
                    dfs(i, j, grid, visited);
                }
        return count;
    }
};