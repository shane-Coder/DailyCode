from typing import List


class Solution:
    def optimalArray(self, n : int, ar : List[int]) -> List[int]:
        # code here
        res = []
        half, full = 0, 0
        for i in range(n):
            full += ar[i]
            if i&1:
                res.append(full - 2*half)
            else:
                half += ar[i//2]
                res.append(full - 2*half + ar[i//2])                
        return res;

#{ 
 # Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        a=IntArray().Input(n)
        
        obj = Solution()
        res = obj.optimalArray(n, a)
        
        IntArray().Print(res)
        

# } Driver Code Ends