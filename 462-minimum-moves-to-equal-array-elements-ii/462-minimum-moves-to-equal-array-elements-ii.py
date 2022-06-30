class Solution:
    def minMoves2(self, v1: List[int]) -> int:
        v1.sort();
        l1 = v1[len(v1)>>1]
        ans1 = 0
        for i in v1:
            ans1 += abs(l1-i)
        return ans1