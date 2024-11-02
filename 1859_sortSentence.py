# https://leetcode.com/problems/sorting-the-sentence/description/?envType=problem-list-v2&envId=rpgwokz5

class Solution:
    def sortSentence(self, s: str) -> str:
        s_list: list[str] = s.split()
        s_list.sort(key = lambda x: x[-1])
        
        for i in range(len(s_list)):
            s_list[i] = s_list[i][:-1]

        return ' '.join(s_list)

S = Solution()
string = "is2 sentence4 This1 a3"
print(S.sortSentence(string))
        