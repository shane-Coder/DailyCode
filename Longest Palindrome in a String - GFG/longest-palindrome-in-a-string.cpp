//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pal(string s, int i, int j){
        while(i>=0 && j<s.length()){
            if(s[i]!=s[j])
                break;
            else{
                j++;
                i--;
            }
        }
        return j-i-1;
    }
    string longestPalin (string s) {
        // code here
        int index=0, m=0;
        for(int i=0; i<s.length(); i++){
            int v = pal(s, i, i+1);
            int r = pal(s, i, i);
            int n = max(v, r);
            if(n>m){
                m = n;
                index = i-(n-1)/2;
            }
        }
        return s.substr(index, m);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends