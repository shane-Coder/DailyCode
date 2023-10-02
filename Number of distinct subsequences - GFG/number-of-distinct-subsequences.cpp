//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int mod = 1e9+7;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int l=s.length();
	    vector<int>end(26,-1);
	    long long dp[l+1];
	    dp[0] = 1;
	    for(int i=1; i<=l; i++){
	        dp[i] = dp[i-1]*2;
	        int occur = end[s[i-1]-'a'];
	        if(occur!=-1){
	            dp[i] -= dp[occur];
	            if(dp[i]<0)
	                dp[i] += mod;
	        }
	        dp[i] %= mod;
	        end[s[i-1]-'a'] = i-1;
	    }
	    return dp[l];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends