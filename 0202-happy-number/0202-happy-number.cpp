class Solution {
public:
    bool isHappy(int n) {
        int slow=n, fast=n;
        do{
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        }while(slow!=fast);
        return slow==1;
    }
    int findSquare(int num){
        int ans=0, d;
        while(num>0){
            d = num%10;
            ans += d*d;
            num = num/10;
        }
        return ans;
    }
};