class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a(rowIndex + 1);
        a[0] = 1;
        for(int i = 1; i <= rowIndex; ++i) {
            a[i] = 1;
            for(int j = i - 1; j > 0; --j)
                a[j] += a[j - 1];
        }
        return a;
    }
};