class Solution {
    public boolean isPerfectSquare(int num) {
        int low=1, high=num, temp=num;
        while(low<=high){
            long mid = low + (high-low)/2;
            if(mid*mid == temp)
                return true;
            else if(mid*mid > temp)
                high = (int)mid-1;
            else
                low = (int)mid+1;
        }
        return false;
    }
}