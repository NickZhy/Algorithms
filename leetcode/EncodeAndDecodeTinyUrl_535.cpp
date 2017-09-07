class Solution {
public:
    // Since we can't avoid the loss of information, 
    // inevitably we need a map to store the relation.
    map<string, string> mp;
    // Designing a hash function is too complex.
    // Here I simply use a random string, and check
    // if there is any conflict.
    // The reson why I'm not using incremental ID as shortUrl 
    // is that it will become a bottleneck of performance when
    // there are a lot of users.
    string randStr(int len) {
        string rst = "";
        for (int i=0; i<len; ++i) {
            int t = rand() % 62;
            char ch;
            if (t < 52) {
                ch = 'A' + t;
            } else {
                ch = '0' + t - 52;
            }
            rst+=ch;
        }
        return rst;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = randStr(6);
        while(mp[shortUrl].size()) {
            shortUrl = randStr(6);
        }
        mp[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

