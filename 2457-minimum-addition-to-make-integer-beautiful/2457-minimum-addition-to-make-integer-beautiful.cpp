class Solution {
public:
    long long help(long long num){
        long long sum=0;
        while(num>0){
            sum += num%10;
            num = num/10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long pow=1, temp=n;
        while(help(n)>target){
            n = n/10 + 1;
            pow = pow*10;
        }
        return n*pow-temp;
    }
};