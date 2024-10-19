# https://leetcode.com/problems/valid-word/
# A word is considered valid if:
    # It contains a minimum of 3 characters.
    # It contains only digits (0-9), and English letters (uppercase and lowercase).
    # It includes at least one vowel.
    # It includes at least one consonant.

# You are given a string word.
# Return true if word is valid, otherwise, return false.

class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        
        vow, cons = 0, 0
        for ch in word:
            if ch.isalnum() == False:
                return False

            if ch in 'aeiouAEIOU':
                vow += 1

            elif ch.isalpha() and ch not in 'aeiouAEIOU':
                cons += 1

        return (vow > 0) and (cons > 0)

s = "234adas"
S = Solution()
print(S.isValid(s))