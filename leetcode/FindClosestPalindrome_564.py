"""
    The idea of this algorithm comes from how you can find the next palindormic of a given one.
    Assume we have a palindormic 121, we can find its next palindormic by first take its left 
    half 12, add 1 to that number, which result in 13, and then generate the right half.
    Notice that there are special cases when the given palindormic is 99, and the adding step 
    result in 10, so the above method gives 1001 as final result. And here I handle this by testing 
    if the length of the result differs from the origin number.
    
"""
class Solution(object):
    def nearPalindromic(self, n, sign):
        mid = (len(n)+1)/2
        left = long(n[:mid])
        left = str(left + sign)
        if len(n) % 2 == 0:
            right = left[::-1]
        else:
            right = left[-2::-1]
        rst = left + right
        if len(rst) < len(n) or rst == '00':
            rst = '9' * (len(n) - 1)
        if len(rst) > len(n):
            rst = '1' + '0' * (len(n) - 1) + '1'
        return rst
    
    def nearestPalindromic(self, n):
        eRst = self.nearPalindromic(n, 0)
        lRst = self.nearPalindromic(n,-1)
        gRst = self.nearPalindromic(n, 1)
        eDiff = abs(long(eRst) - long(n))
        lDiff = abs(long(lRst) - long(n))
        gDiff = abs(long(gRst) - long(n))
        minDiff = eDiff
        minRst = eRst
        if eDiff == 0:
            minDiff = float('inf')   
        if lDiff <= minDiff:
            minDiff = lDiff
            minRst = lRst
        if gDiff < minDiff:
            minRst = gRst
        return minRst
