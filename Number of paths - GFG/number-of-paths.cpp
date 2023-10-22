//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long mod = 1e9+7;
    long long power(long long x, int y){
        long long res = 1;
        while(y>0){
            if(y&1)
                res = (res*x)%mod;
                y = y>>1;
                x = (x*x)%mod;
        }
        return res;
    }
    long long modInverse(long long n){
        return power(n, mod-2);
    }
    long long  numberOfPaths(int m, int n)
    {
        // Code Here
        long long path=1;
        for(long long i=n; i<(m+n-1); i++){
            path = (path*i)%mod;
            long long val = modInverse(i-n+1);
            path = (path*val)%mod;
        }
        return path;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends