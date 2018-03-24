class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rst;
        int currlen = 0;
        int i = 0;
        for(int offset = 0; i + offset < words.size();) {
            if(currlen + offset + words[i + offset].size() <= maxWidth) {
                currlen += words[i + offset].size();
                ++offset;
            }else {
                string str = "";
                if(offset == 1) {
                    str = words[i + offset - 1] + string(maxWidth - currlen, ' ');
                }else {
                    int each = (maxWidth - currlen)/(offset - 1);
                    for(int n = 0; n < offset - 1; ++n) {
                        int oneMore = n < (maxWidth - currlen)%(offset - 1) ;
                        str += words[i + n] + string(each + oneMore, ' ');
                    }
                    str += words[i + offset - 1];
                }
                rst.push_back(str);
                i = offset + i;
                currlen = 0;
                offset = 0;
            }
        }
        string str = "";
        while(i < words.size())
             str += words[i++] + ' ';
        str.pop_back();
        str += string(maxWidth - str.size(), ' ');
        rst.push_back(str);
        return rst;
    }
};