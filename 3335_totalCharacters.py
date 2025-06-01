from string import ascii_lowercase

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        dic = {char:chr(ord(char)+1) for char in ascii_lowercase}
        dic['z'] = 'ab'
        return dic

        # res = ''
        # for _ in range(t):
        #     res = ''.join(dic[string] for string in res)
        # return res


S = Solution()
s = "abcyy"
t = 2
print(S.lengthAfterTransformations(s, t)) 
# print(ascii_lowercase)