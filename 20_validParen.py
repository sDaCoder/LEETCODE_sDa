class Solution:
    def __init__(self) -> None:
        self.stack = []
    
    def match(self, a: str, b: str) -> bool:
        if a == '(' and b == ')':
            return True
        elif a == '[' and b == ']':
            return True
        elif a == '{' and b == '}':
            return True
        else:
            return False
    
    def isValid(self, s: str) -> bool:
        for i in s:
            if i in ['(', '[', '{']:
                self.stack.append(i)
            else:
                if self.stack != [] and self.match(self.stack[-1], i):
                    self.stack.pop()
                else:
                    return False
        return self.stack == []
    
S = Solution()
s = "([)]"
print(S.isValid(s))