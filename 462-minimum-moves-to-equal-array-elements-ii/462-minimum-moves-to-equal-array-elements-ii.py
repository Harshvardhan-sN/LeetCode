class Solution:
    def minMoves2(self, v1: List[int]) -> int:
        v1.sort();
        n = len(v1)
        l1 = v1[n//2]
        ans1 = 0
        for i in v1:
            ans1 += abs(l1-i)
        return ans1