//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        vector<int> res(n+1,0);
        for(int i=0; i<n; i++){
            if(s[i]=='1')
                res[max(0,i-x)]++,res[min(n,i+x+1)]--;
        }
        if(res[0]<=0)
            return false;
        for(int i=1; i<n; i++){
            res[i] += res[i-1];
            if(res[i]<=0)   return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends