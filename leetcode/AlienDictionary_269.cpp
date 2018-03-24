class Solution {
public:
    bool topoSort(char ch, int *visited, string& rst, unordered_map<char, unordered_set<char>> seq) {
        if(visited[ch - 'a'] == 2) return true;
        if(visited[ch - 'a'] == 1) return false;
        visited[ch - 'a'] = 1;
        for(auto c: seq[ch])
            if(!topoSort(c, visited, rst, seq))
                return false;
        visited[ch - 'a'] = 2;
        rst += ch;
        return true;
    }
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> seq;
        unordered_map<char, bool> hasFather;
        int len = words.size();
        
        for(string wd: words)
            for(char ch: wd)
                hasFather[ch] = false;
        
        for(int i = 0; i < len - 1; ++i) {
            for(int j = i + 1; j < len; ++j) {
                int  k = 0;
                int wLen1 = words[i].size();
                int wLen2 = words[j].size();
                while(k < wLen1 && k < wLen2 && words[i][k] == words[j][k]) ++k;
                if(k < wLen1 && k < wLen2) {
                    seq[words[j][k]].insert(words[i][k]);                    
                    hasFather[words[i][k]] = true;
                }
            }
        }
        
        string rst = "";
        int visited[26] = {0};
        for(auto pair: hasFather) {
            if(!pair.second) {
                if(!topoSort(pair.first, visited, rst, seq)) return "";
            }
        }
        for(auto pair: hasFather) 
            if(!visited[pair.first - 'a']) return "";
        return rst;
    }
};