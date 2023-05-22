//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int n, vector<int> p){
        // code here
        int res=n-1;
        vector<int>degree(n+1,0);
        for(int i=1; i<n; i++){
            degree[p[i]]++;
            degree[i]++;
        }
        for(int i=0; i<n+1; i++){
            if(degree[i]==1)
                res--;
        }
        if(res<0)
            return 0;
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends