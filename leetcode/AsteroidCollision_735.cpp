class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for(int ast: asteroids) {
            if(ast > 0) {
                stk.push_back(ast);
            } else {
                while(stk.size() > 0 && (0 <= stk.back() && stk.back() < -ast)) 
                    stk.pop_back();
                if(stk.size() == 0 || stk.back() < 0) {
                    stk.push_back(ast);
                } else if(stk.back() == -ast) {
                    stk.pop_back();
                }
            }
        }
        
        return stk;
    }
};