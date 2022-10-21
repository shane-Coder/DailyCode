class Solution {
    public int subtractProductAndSum(int n) {
        int mul=1, sum=0, d;
        while(n!=0){
            d = n%10;
            mul = mul*d;
            sum = sum+d;
            n = n/10;
        }
        return mul-sum;
    }
}