class Solution {
public:
    unordered_map<string, string> s2l;
    
    string randStr(int len) {
        string rst = "";
        for(int i = 0; i < len; ++i) {
            int num = rand() % 62;
            if(num < 26)
                rst += 'a' + num;
            else if(num < 52)
                rst += 'A' + num - 26;
            else
                rst += '0' + num - 52;
        }
        return rst;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = randStr(6);
        while(s2l.count(shortUrl) > 0)
            shortUrl = randStr(6);
        s2l[shortUrl] = longUrl;
        return "http://tinyurl.com/" + shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s2l[shortUrl.substr(19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));