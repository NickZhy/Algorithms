typedef pair<int, int> pos;
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    
    int bfs(vector<vector<int>>& forest, pos curr, pos end) {        
        int hei = forest.size(), wid = forest[0].size();
        vector<vector<int>> visited(hei, vector<int>(wid, 0));
        queue<pos> que;
        que.push(curr);
        visited[curr.first][curr.second] = 1;
        int step = 0;
        while(que.size() && !step) {
            pos p = que.front();
            que.pop();
            int &x = p.first, &y = p.second;
            if(p == end) {
                step = visited[x][y];
            } else {
                if(x > 0 && forest[x - 1][y] && !visited[x - 1][y]) {
                    visited[x - 1][y] = visited[x][y] + 1;
                    que.push(pos(x - 1, y));
                }

                if(y > 0 && forest[x][y - 1] && !visited[x][y - 1]) {
                    visited[x][y - 1] = visited[x][y] + 1;
                    que.push(pos(x, y - 1));
                }

                if(x + 1 < hei && forest[x + 1][y] && !visited[x + 1][y]) {
                    visited[x + 1][y] = visited[x][y] + 1;
                    que.push(pos(x + 1, y));
                }

                if(y + 1 < wid && forest[x][y + 1] && !visited[x][y + 1]) {
                    visited[x][y + 1] = visited[x][y] + 1;
                    que.push(pos(x, y + 1));
                }
            }
        }
        return step - 1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        int hei = forest.size();
        if(!hei) return 0;
        int wid = forest[0].size();
        if(!wid) return 0;
        vector<vector<int>> trees;
        for(int i = 0; i < hei; ++i)
            for(int j = 0; j < wid; ++j)
                if(forest[i][j] > 1) {
                    vector<int> tree;
                    tree.push_back(forest[i][j]);
                    tree.push_back(i); tree.push_back(j);
                    trees.push_back(tree);
                }
        int result = 0;
        sort(trees.begin(), trees.end(), cmp);
        pos curr(0, 0);
        for(auto &tree: trees) {
            pos end(tree[1], tree[2]);
            int step = bfs(forest, curr, end);
            if(step < 0) return -1;
            result += step;
            curr = end;
        }
        return result;
    }
};