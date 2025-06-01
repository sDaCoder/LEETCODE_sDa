class Solution:

    def sqrtRecur(self, x: int, L: int, R: int):
        mid = L + (R - L) // 2
        if mid ** 2 == x:
            return mid
        elif mid ** 2 < x:
            return self.sqrtRecur(x, mid + 1, R)
        else:
            return self.sqrtRecur(x, L, mid - 1)

    def mySqrt(self, x: int):
        L, R = 1, x

        while L <= R:
            mid = (L + R) // 2
            if mid ** 2 == x:
                return mid
            elif mid ** 2 < x:
                L = mid + 1
            else:
                R = mid - 1

        return R
    
S = Solution()
print(S.mySqrt(8))
# print(S.sqrtRecur(8, 1, 8))