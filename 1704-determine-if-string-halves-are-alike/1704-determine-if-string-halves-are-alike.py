class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        l, r, vo = 0, 0, "aeiouAEIOU"
        for i in range(len(s)):
            if s[i] in vo:
                if i<len(s)//2:
                    l = l + 1
                else:
                    r = r + 1
        return l == r
        