class Solution {
public:
    int peakIndexInMountainArray(vector<int>& ar) {
        int low=0, high=ar.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(ar[mid]>ar[mid-1] and ar[mid]>ar[mid+1])
                return mid;
            else if(ar[mid]<ar[mid-1])
                high = mid;
            else
                low = mid;
        }
        return -1;
    }
};