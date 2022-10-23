class Solution:
    def canMakeArithmeticProgression(self, ar: List[int]) -> bool:
        ar.sort()
        value = ar[1]-ar[0]
        for i in range(1,len(ar)):
            if ar[i]-ar[i-1] == value:
                continue
            else:
                return False
        return True