class Solution {
public:
    /*
	state transformation:
    if s[i - 1] == p[j - 1] || p[j - 1] == '?'
        dp[i][j] = dp[i - 1][j - 1]
    if p[j - 1] == '*'
        dp[i][j] = exist x <= i, so dp[x][j - 1] 

        this is equivalent to:
            dp[i][j] = dp[i][j - 1] || dp[i - 1][j]
        proof:
            =>
            because p[j] == '*', if d[i][j - 1] is true obviously dp[i][j] is true,
            meanwhile, if d[i - 1][j] is true, when '*' matches nothing dp[i][j] is also true.
            <=
            if dp[i][j] is true, there exists x <= i so dp[x][j - 1] is true,
            when x == i, obviously dp[i][j - 1] is true.
            otherwise, there exists x <= i - 1, dp[x][j] is true, so that dp[i - 1][j ] is also true.

		This is also suitable in other dynamic programming problems. An exist condition always results in
		easier state transformation equations.
    */

	// dp algorithm
    bool isMatch(string s, string p) {
        if(!s.size() && !p.size())
            return true;
        if(!p.size())
            return false;
        vector<vector<bool> > dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        
        for(int j = 1; j < p.size() + 1; ++j) {
            for(int i = 0; i < s.size() + 1; ++i) {
                if(i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                    dp[i][j] =  dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    dp[i][j] = (i > 0 && dp[i - 1][j]) || dp[i][j - 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
    
	// Space Optimization 
    bool isMatch(string s, string p) {
        if(!s.size() && !p.size())
            return true;
        if(!p.size())
            return false;
        vector<bool> dp1(p.size() + 1, false);
        vector<bool> dp2(p.size() + 1, false);
        vector<bool>* dpOld = &dp1;
        vector<bool>* dpNew = &dp2;
        for(int i = 0; i < s.size() + 1; ++i) {
            (*dpNew)[0] = i == 0;
            for(int j = 1; j < p.size() + 1; ++j) {
                if(i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                    (*dpNew)[j] = (*dpOld)[j - 1];
                } else if(p[j - 1] == '*') {
                    (*dpNew)[j] = (i > 0 && (*dpOld)[j]) || (*dpNew)[j - 1];
                } else {
                    (*dpNew)[j] = false;
                }
            }
            swap(dpNew, dpOld);
        }
        return (*dpOld)[p.size()];
    }
};
