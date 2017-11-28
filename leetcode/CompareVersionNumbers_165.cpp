class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        
        int start1 = 0, start2 = 0;
        while(start1 < len1 && start2 < len2) {
            int c1 = 0, c2 = 0;
            while(start1 + c1 < len1 && version1[start1 + c1] != '.') ++c1;
            while(start2 + c2 < len2 && version2[start2 + c2] != '.') ++c2;
            int v1 = stoi(version1.substr(start1, c1));
            int v2 = stoi(version2.substr(start2, c2));
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
            start1 += c1 + 1;
            start2 += c2 + 1;
        }
        while(start1 < len1) {
            if(version1[start1] != '.' && version1[start1] != '0') return 1;
            ++start1;
        }
        while(start2 < len2) {
            if(version2[start2] != '.' && version2[start2] != '0') return -1;
            ++start2;
        }
        return 0;
    }
};
