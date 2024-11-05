# Definition for a binary tree node.
from typing import Optional, List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, values: list[int]) -> TreeNode | None:
        if values[0] == -1 or len(values) == 0:
            return 
        
        root: TreeNode = TreeNode(values[0])
        Q: list[TreeNode] = [root]
        i: int = 1

        while i < len(values) and len(Q) > 0:
            temp: TreeNode = Q.pop(0)
            if (i < len(values) and values[i] != -1):
                temp.left = TreeNode(values[i])
                Q.append(temp.left)
            i += 1

            if (i < len(values) and values[i] != -1):
                temp.right = TreeNode(values[i])
                Q.append(temp.right)
            i += 1

        return root

    def preOrder(self, root: Optional[TreeNode]) -> None:
        if root is not None:
            print(root.val, end=" ")
            self.preOrder(root.left)
            self.preOrder(root.right)
            
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:    
        if root is None:
            return []

        ans: List[float] = []
        Q: List[TreeNode] = [root]

        while len(Q) > 0:
            level_sum: float = 0
            n: int = len(Q)

            for i in range(n):
                temp: TreeNode = Q.pop(0)
                level_sum += temp.val

                if temp.left is not None: Q.append(temp.left)
                if temp.right is not None: Q.append(temp.right)

            ans.append(level_sum / n)
        return ans
        
S = Solution()
nodes: list[int] = [3, 9, 20, -1, -1, 15, 7]

root: TreeNode | None = S.buildTree(nodes)
S.preOrder(root)        

print(S.averageOfLevels(root))