class Solution {
    public int maximumGap(int[] nums) {
        if(nums.length <= 1) return 0;
        int maxNum = Integer.MIN_VALUE, minNum = Integer.MAX_VALUE;
        for(int n: nums) {
            maxNum = Math.max(maxNum, n);
            minNum = Math.min(minNum, n);
        }
        int bucketSize = Math.max((maxNum - minNum) / (nums.length - 1), 1);
        int bucketNum = (maxNum - minNum) / bucketSize + 1;
        System.out.println(bucketSize);
        
        if(bucketNum <= 1) return maxNum - minNum;

        int bucketMax[] = new int[bucketNum];
        int bucketMin[] = new int[bucketNum];
        boolean bucketHasNum[] = new boolean[bucketNum];
        for(int n: nums) {
            int pos = (n - minNum) / bucketSize;
            if(!bucketHasNum[pos]) {
                bucketMax[pos] = n;
                bucketMin[pos] = n;
                bucketHasNum[pos] = true;
            } else {
                bucketMax[pos] = Math.max(bucketMax[pos], n);
                bucketMin[pos] = Math.min(bucketMin[pos], n);
            }
        }
        int maxGap = 0, lastMax = minNum;
        for(int i = 0; i < bucketNum; ++i) {
            if(bucketHasNum[i]) {
                maxGap = Math.max(maxGap, bucketMin[i] - lastMax);
                lastMax = bucketMax[i];
            }
        }
        return maxGap;
    }
}