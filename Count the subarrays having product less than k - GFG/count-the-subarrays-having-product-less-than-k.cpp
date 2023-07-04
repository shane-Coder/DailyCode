//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& ar, int n, long long k) {
        int ct=0;
        long long p=1;
        int j=0;
        for(int i=0; i<n; i++){
            p *= ar[i];
            while(p>=k && j<=i){
                p /= ar[j];
                j++;
            }
            ct += (i-j+1);
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends