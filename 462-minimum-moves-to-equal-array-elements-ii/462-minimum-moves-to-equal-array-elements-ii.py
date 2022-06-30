class Solution:
    def minMoves2(self, v1: List[int]) -> int:
        v1.sort();
        l1 = v1[len(v1)>>1]
        ans1 = 0
        for i in v1:
            if l1>i:
                ans1 += l1-i
            else:
                ans1 += i-l1
        return ans1