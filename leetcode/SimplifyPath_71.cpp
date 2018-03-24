class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        int end = 0;
        int start = 0;
        while(start < path.size()) {
            while(end < path.size() && path[end] != '/') ++end;
            if(start != end) {
                string curr = path.substr(start, end - start);
                if(curr == "..") {
                    if(stk.size()) stk.pop_back();
                } else if(curr != ".") {
                    stk.push_back(curr);
                }
            }
            start = ++end;
            
        }
        if(!stk.size()) return "/";
        string rst = "";
        for(auto s: stk) rst += "/" + s;
        return rst;
    }
};