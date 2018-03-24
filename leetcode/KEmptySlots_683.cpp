class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int len = flowers.size();
        if(len < 2 || k >= len) return -1;
        int numBucket = len / (k + 1) + 3;
        vector<int> bucketUpper(numBucket, -200000);
        vector<int> bucketLower(numBucket, 200000);
        for(int i = 0; i < len; ++i) {
            int pos = flowers[i] - 1;
            int bucketIdx = pos / (k + 1) + 1;
            if(pos > bucketUpper[bucketIdx]) {
                //outside same bucket
                if(bucketLower[bucketIdx + 1] - pos == k + 1)
                    return i + 1;
                bucketUpper[bucketIdx] = pos;
            }
            
            if(pos < bucketLower[bucketIdx]) {
                if(pos - bucketUpper[bucketIdx - 1] == k + 1)
                    return i + 1;
                bucketLower[bucketIdx] = pos;
            }
        }
        return -1;
    }
};