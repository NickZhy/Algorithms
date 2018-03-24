typedef pair<char, int> pr;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        vector<pr> stk;
        stk.push_back(pr('(', 0));
        int leftPar = 1;
        int rightPar = 0;
        while(stk.size()) {
            if(stk.size() == 2 * n) {
                string tmp = "";
                for(auto p: stk)
                    tmp += p.first;
                rst.push_back(tmp);
            }
            pr curr = stk.back();
            stk.pop_back();
            if(curr.second == 0 && leftPar < n) {
                curr.second = 1;
                stk.push_back(curr);
                stk.push_back(pr('(', 0));
                ++leftPar;
            } else if(curr.second <= 1 && rightPar < leftPar) {
                curr.second = 2;
                stk.push_back(curr);
                stk.push_back(pr(')', 0));
                ++rightPar;
            } else {
                if(curr.first == '(') --leftPar;
                if(curr.first == ')') --rightPar;
            }
        }
        return rst;
    }
};