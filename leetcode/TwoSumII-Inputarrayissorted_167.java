class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int rst[] = new int[2];
        rst[0] = 0; rst[1] = numbers.length - 1;
        while(rst[0] < rst[1]) {
            int t = numbers[rst[0]] + numbers[rst[1]];
            if(t == target) {
                break;
            } else if(t < target) {
                ++rst[0];
            } else {
                --rst[1];
            }
        }
        ++rst[0];
        ++rst[1];
        return rst;
    }
}