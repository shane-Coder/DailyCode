//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int ar[], int n) {
        // code here
        int index=0;
        for(int j=n-1; j>=1; j--){
            int i=0;
            while(i<j){
                if(ar[i]<=ar[j]){
                    index = max(index, j-i);
                    break;
                }
                i++;
            }
        }
        return index;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends