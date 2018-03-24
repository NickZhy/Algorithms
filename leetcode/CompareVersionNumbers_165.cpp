class Solution {
public:
    int readNumber(string& str, int& pos) {
        while(pos < str.size() && str[pos] == '0') ++pos;
        int rst = 0;
        while(pos + rst < str.size() && str[pos + rst] != '.') ++rst;
        return rst;
    }
    
    int compareVersion(string version1, string version2) {
        int id1 = 0, id2 = 0;
        int c1 = 0, c2 = 0;
        while(id1 < version1.size() && id2 < version2.size()) {
            int c1 = readNumber(version1, id1);
            int c2 = readNumber(version2, id2);
            if(c1 < c2) return -1;
            if(c1 > c2) return  1;
            int cmp = version1.substr(id1, c1).compare(version2.substr(id2, c2));
            if(cmp > 0) return  1;
            if(cmp < 0) return -1;
            id1 += c1 + 1;
            id2 += c2 + 1;
        }
        while(id1 < version1.size()) {
            if(version1[id1] != '0' && version1[id1] != '.') return 1;
            ++id1;
        }
        while(id2 < version2.size()) {
            if(version2[id2] != '0' && version2[id2] != '.') return -1;
            ++id2;
        }
        return 0;
    }
};