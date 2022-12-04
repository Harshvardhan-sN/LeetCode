class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        l, r = 0, len(skill)-1
        req, ans = skill[l] + skill[r], 0
        while l<r:
            diff = skill[l] + skill[r]
            ans = ans + skill[l] * skill[r]
            l, r = l + 1, r - 1
            if req != diff:
                return -1
        return ans