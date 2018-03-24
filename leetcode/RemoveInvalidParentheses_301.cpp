typedef pair<string, int> pr;
class Solution {
public:
    bool isValid(string& s) {
        int c = 0;
        for(char ch: s) {
            if(ch == '(') {
                ++c;
            } else if(ch == ')') {
                --c;
                if(c < 0) return false;
            }
        }
        return c == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> rst;
        int maxDepth = INT_MAX;
        unordered_set<string> visited;
        visited.insert(s);
        queue<pr> q;
        q.push(pr(s, 0));
        while(q.size()) {
            pr curr = q.front();
            q.pop();
            string& str = curr.first;
            int& depth = curr.second;
            if(depth > maxDepth) break;
            if(isValid(str)) {
                rst.push_back(str);
                maxDepth = depth;
            } else {
                for(int i = 0; i < str.size(); ++i) {
                    string child = str.substr(0, i) + str.substr(i + 1);
                    if(!visited.count(child)) {
                        visited.insert(child);
                        q.push(pr(child, depth + 1));
                    }
                }
            }
        }
        return rst;
    }
};