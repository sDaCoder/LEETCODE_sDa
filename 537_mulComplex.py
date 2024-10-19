# https://leetcode.com/problems/complex-number-multiplication/
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        num1 = num1.replace("i", "")
        num2 = num2.replace("i", "")
        a, b = num1.split("+")
        c, d = num2.split("+")
        return f"{(int(a) * int(c)) - (int(b) * int(d))}+{(int(a) * int(d)) + (int(b) * int(c))}i"

num1 = "1+-1i"
num2 = "1+-1i"
s = Solution()
print(s.complexNumberMultiply(num1, num2))