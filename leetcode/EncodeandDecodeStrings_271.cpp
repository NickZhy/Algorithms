class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string rst = "";
        for(string& s: strs) {
            for(char ch: s) {
                switch(ch) {
                    case '"':
                    case '\\': rst += '\\';
                    default: rst += ch;
                }
            }
            rst += '"';
        }
        return rst;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int idx = 0, len = s.size();
        vector<string> rst;
        while(idx < len) {
            string tmp = "";
            while(idx < len && s[idx] != '"') {
                if(s[idx] == '\\') {
                    assert(idx + 1 < len);
                    tmp += s[idx + 1];
                    idx += 2;
                } else {
                    tmp += s[idx++];
                }
            }
            ++idx;
            rst.push_back(tmp);
        }
        return rst;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));