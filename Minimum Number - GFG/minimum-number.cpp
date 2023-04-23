//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n, vector<int> &ar){
        // Code here
        int m=INT_MAX;
        for(int i=0; i<n; i++){
            m = min(m,ar[i]);
        }
        int res = m;
        for(int i=0; i<n; i++){
            if(ar[i]%m==0)
                continue;
            res = min(res,ar[i]%m);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends