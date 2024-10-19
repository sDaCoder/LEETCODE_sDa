class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.strip().lower()
        for ch in s:
            if not ch.isalnum():
                s = s.replace(ch, "")
        return s == s[::-1]
    
S = Solution()
s = "   "
print(S.isPalindrome(s))