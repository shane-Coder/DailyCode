//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long maxGcd(int n) {
        // code here
        long long int res=n*(n-1);
        int x=0;
        for(long long int i=n-2; i>2 && x<2; i--){
            if(__gcd(res,i)==1){
                res = res*i;
                x++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends