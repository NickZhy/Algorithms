class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> rst;
        for(int n: nums1) s.insert(n);
        for(int n: nums2) {
            if(s.count(n)) {
                rst.push_back(n);
                s.erase(n);
            }
        }
        return rst;
    }
};