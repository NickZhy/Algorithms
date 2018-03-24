class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int i, int j, int dist) {
        if(i < 0 || i >= rooms.size()) return;
        if(j < 0 || j >= rooms[0].size()) return;
        if(rooms[i][j] < dist) return;
        rooms[i][j] = dist;
        dfs(rooms, i - 1, j, dist + 1);
        dfs(rooms, i, j - 1, dist + 1);
        dfs(rooms, i + 1, j, dist + 1);
        dfs(rooms, i, j + 1, dist + 1);
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i = 0; i < rooms.size(); ++i)
            for(int j = 0; j < rooms[0].size(); ++j)
                if(rooms[i][j] == 0)
                    dfs(rooms, i, j, 0);
    }
};