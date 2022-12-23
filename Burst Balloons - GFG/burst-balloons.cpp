//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int solve(int s ,int e ,vector<int>&nums ,vector<vector<int>>& dp){
        if(s>e) return 0;
        if(s==e) return nums[e-1]*nums[e]*nums[e+1];
       
        if(dp[s][e]!=-1) return dp[s][e];  //dp state: max collection in [s,e] range
       
        dp[s][e] = INT_MIN;
        for( int k=s ; k<=e ; k++ ){
            dp[s][e] = max(dp[s][e], solve(s,k-1,nums,dp)+(nums[s-1]*nums[k]*nums[e+1])+solve(k+1,e,nums,dp));
        }
       
        return dp[s][e] ;
    }
    int maxCoins(int n, vector<int> &nums) {
        // code here
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        vector<int> arr;
        arr.push_back(1) ; 
        for(int &i:nums) arr.push_back(i); arr.push_back(1);
        return solve( 1 , n , arr , dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends