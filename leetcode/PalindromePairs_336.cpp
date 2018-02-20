class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        --j;
        while(i < j) 
            if(s[i++] != s[j--]) return false;
        return true;
    }
	
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> rst;
        map<string, vector<int>> wSet;
        for(int i = 0; i < words.size(); ++i)
            wSet[words[i]].push_back(i);
        
        for(int i = 0; i < words.size(); ++i) {
            string wd = words[i];
            int wLen = wd.size();
            for(int j = wLen; j >= 0; --j) {
                if(isPalindrome(wd, j, wLen)) {
                    string rvHead = wd.substr(0, j);
                    reverse(rvHead.begin(), rvHead.end());
                    for(int pos: wSet[rvHead]) {
                        if(pos == i) continue;
                        vector<int> pair;
                        pair.push_back(i);
                        pair.push_back(pos);
                        rst.push_back(pair);
                    }
                }
            }
            
            for(int j = 1; j <= wLen; ++j) {
                if(isPalindrome(wd, 0, j)) {
                    string rvTail = wd.substr(j);
                    reverse(rvTail.begin(), rvTail.end());
                    for(int pos: wSet[rvTail]) {
                        if(pos == i) continue;
                        vector<int> pair;
                        pair.push_back(pos);
                        pair.push_back(i);
                        rst.push_back(pair);
                    }
                }
            }
        }
        return rst;
    }
};
