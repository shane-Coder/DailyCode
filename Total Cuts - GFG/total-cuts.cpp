//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n, int k, vector<int> &ar){
        // Code here
        vector<int>left(n);
        left[0] = ar[0];
        for(int i=1; i<n; i++)
            left[i] = max(left[i-1],ar[i]);
        vector<int>right(n);
        right[n-1] = ar[n-1];
        for(int i=n-2; i>=0; i--)
            right[i] = min(right[i+1],ar[i]);
        int ct=0;
        for(int i=0; i<n-1; i++){
            if(left[i]+right[i+1]>=k)
                ct++;
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends