//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int ar[], int n) {
        // code here
        vector<int>v;
        for(int i=0; i<n; i++){
            ar[ar[i]%n] += n;
        }
        for(int i=0; i<n; i++){
            if(ar[i]/n > 1)
                v.push_back(i);
        }
        if(v.empty())
            return {-1};
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends