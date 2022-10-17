class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ct = 0
        while target!=1:
            if target%2==0 and maxDoubles!=0:
                target = target//2
                maxDoubles -= 1
                ct += 1
            elif maxDoubles==0:
                ct += target-1
                target = 1
            else:
                target -= 1
                ct += 1
        return ct