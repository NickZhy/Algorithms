class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(abbr.size() > word.size()) return false;
        int i = 0, j = 0;
        while(i < abbr.size() && j < word.size()) {
            if(isdigit(abbr[i])) {
                if(abbr[i] == '0') return false;
                int num = 0;
                while(i < abbr.size() && isdigit(abbr[i])) 
                    num = num * 10  + abbr[i++] - '0';
                j += num;
            } else {
                if(abbr[i] != word[j]) 
                    return false;
                ++i; ++j;
            }
        }
        return j == word.size() && i == abbr.size();
    }
};