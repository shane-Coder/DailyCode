//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int l=s.length(), ct=1;
        for(int i=0; i<l/2; i++){
            int x=0, d=i+1;
            for(int j=d; j<2*d; j++){
                if(s[j-i-1]==s[j])  x++;
                else    break;
            }
            ct = max(ct,x);
        }
        return l-ct+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends