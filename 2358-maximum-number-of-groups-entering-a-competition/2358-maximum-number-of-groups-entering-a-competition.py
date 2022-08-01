class Solution:
    def maximumGroups(self, g: List[int]) -> int:
        n, m, ans, i = len(g), 0, 0, 1
        while m<n:
            m += i
            i += 1
            ans += 1      
        return ans - 1 if m>n else ans