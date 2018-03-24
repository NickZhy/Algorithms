class Solution {
    public int maxProduct(int[] nums) {
        int prod = 1, maxProd = Integer.MIN_VALUE;
        int maxNegProd = 1;
        for(int i = 0; i < nums.length; ++i) {
            prod *= nums[i];
            maxProd = Math.max(maxProd, prod);
            if(prod < 0) {
                maxProd = Math.max(maxProd, prod / maxNegProd);
                maxNegProd = maxNegProd == 1? prod: Math.max(maxNegProd, prod);
            }
            if(nums[i] == 0) {
                prod = 1;
                maxNegProd = 1;
            }
        }
        return maxProd;
    }
}