//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool possible(int ar[], int mid, int k, int n){
        int take=0;
        long long sum=0;
        for(int i=0; i<n; i++){
            if(ar[i]>mid)
                return false;
            sum += ar[i];
            if(sum>mid){
                sum = ar[i];
                take++;
            }
            else if(sum==mid){
                sum = 0;
                take++;
            }
        }
        if(sum!=0) take++;
        if(take<=k)
            return true;
        return false;
    }
  public:
    int splitArray(int ar[] ,int n, int k) {
        // code here
        long long int sum=0;
        for(int i=0; i<n; i++)
            sum += ar[i];
        long long int low=1, high=sum;
        int res=INT_MAX;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(possible(ar, mid, k, n)){
                res = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends