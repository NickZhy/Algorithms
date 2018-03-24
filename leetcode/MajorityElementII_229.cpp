class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int y = 0, z = 1, cy = 0, cz = 0;
        for (auto x: nums) {
          if (x == y) cy++;
          else if (x == z) cz++;
          else if (! cy) y = x, cy = 1;
          else if (! cz) z = x, cz = 1;
          else cy--, cz--;
        }
        cy = cz = 0;
        for (auto x: nums)
          if (x == y) cy++;
          else if (x == z) cz++;
        vector<int> r;
        if (cy > nums.size()/3) r.push_back(y);
        if (cz > nums.size()/3) r.push_back(z);
        return r;
    }
};