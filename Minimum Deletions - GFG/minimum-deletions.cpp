//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        string temp=s;
        reverse(temp.begin(), temp.end());
        int l = s.length();
        vector<int>pre(l+1, 0);
        for(int i=1; i<=l; i++){
            vector<int>curr(l+1, 0);
            for(int j=1; j<=l; j++){
                if(s[i-1]==temp[j-1]){
                    curr[j] = 1+pre[j-1];
                    continue;
                }
                int x = pre[j];
                int y = curr[j-1];
                curr[j] = max(x, y);
            }
            pre = curr;
        }
        return l-pre[l];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends