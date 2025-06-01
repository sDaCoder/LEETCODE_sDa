from typing import List
import heapq
import math

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        ADJL = [[] for _ in range(n)]
        

        PQ = []
        dist: List[int] = [math.inf for _ in range(n)]
        dist[src] = 0
        heapq.heappush(PQ, tuple((0, src)))

        while PQ:
            dist, node = heapq.heappop(PQ)
            pass

        return -1

S = Solution()
src = 0
dst = 4
k = 1
n = 4
flights: List[List[int]] = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
print(S.findCheapestPrice(n, flights, src, dst, k))