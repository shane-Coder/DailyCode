//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int res=0, l=s.length();
        for(int i=0; i<l/2; i++){
            if(s[i]=='?' && s[l-1-i]!='?')
                s[i] = s[l-1-i];
            else if(s[i]!=s[l-1-i] && s[i]!='?' && s[l-1-i]!='?')
                return -1;
        }
        char ch='.';
        for(int i=0; i<l/2; i++){
            if(s[i]!='?'){
                if(ch=='.')
                    ch = s[i];
                else if(s[i]!=ch)
                    res += abs(s[i]-ch);
                ch = s[i];
            }
        }
        return res*2;
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
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends