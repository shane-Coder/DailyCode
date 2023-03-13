//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int n, vector<int> ar, vector<int> br) {
        // code here
        long long m=INT_MAX, ct=0, res=0;
        for(int i=0; i<n; i++){
            if(ar[i]<m && br[i]>1)
                m = ar[i];
            int diff = br[i]/2;
            res += diff*2*ar[i];
            ct += diff*2;
        }
        if(ct%4!=0)
            res -= m*2;
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends