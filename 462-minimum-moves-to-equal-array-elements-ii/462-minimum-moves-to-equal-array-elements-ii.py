class Solution:
    def minMoves2(self, v1: List[int]) -> int:
        v1.sort();
        l1, ans1 = v1[len(v1)>>1],0
        for i in v1:
            ans1 += abs(i-l1)
        return ans1;