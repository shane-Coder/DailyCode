//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int x, int ar[], int total, vector<vector<int>>&dp){
        if(x<0){
            if(total==0)    return 1;
            else    return 0;
        }
        if(dp[x][total]!=-1)    return dp[x][total];
        int temp=0;
        if(ar[x]<=total){
            temp = solve(x-1, ar, total-ar[x], dp);
        }
        int take = solve(x-1, ar, total, dp);
        dp[x][total] = take+temp>0?1:0;
        return dp[x][total];
    }
    
    int equalPartition(int n, int ar[])
    {
        // code here
        int total=0;
        for(int i=0; i<n; i++){
            total += ar[i];
        }
        if(total%2)
            return 0;
        vector<vector<int>>dp(n, vector<int>(total/2+1, -1));
        return solve(n-1, ar, total/2, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends