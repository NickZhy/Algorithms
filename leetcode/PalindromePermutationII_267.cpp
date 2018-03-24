class Solution {
    void perm(string curr, int i, vector<string>& rst) {
        int len = curr.size();
        if(i == len) {
            rst.push_back(curr);
            return;
        }
        for(int j = i; j < len; ++j) {
            if(j != i && curr[j] == curr[i]) continue;
            swap(curr[i], curr[j]);
            perm(curr, i + 1, rst);
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        int count[256] = { 0 };
        for(char ch: s)
            ++count[ch];

        char single = '\0';
        bool hasSingle = false;
        for(int i = 0; i < 256; ++i) {
            if(count[i] % 2) {
                if(hasSingle) return { };
                hasSingle = true;
                single = i;
            }
            count[i] /= 2;
        }
        string str = "";
        for(int i = 0; i < 256; ++i) 
            for(int j = 0; j < count[i]; ++j)
                str.push_back(i);
        
        vector<string> rst;
        perm(str, 0, rst);
        
        for(int i = 0; i < rst.size(); ++i) {
            string tmp = rst[i];
            reverse(tmp.begin(), tmp.end());
            if(hasSingle) 
                rst[i].push_back(single);
            rst[i] += tmp;
        }
        return rst;
    }
};