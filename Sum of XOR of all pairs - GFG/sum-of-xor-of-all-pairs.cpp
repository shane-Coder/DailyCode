//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int ar[], int n)
    {
    	//Complete the function
    	long long int res=0;
    	for(int i=0; i<31; i++){
    	    long long int ct1=0, ct2=0;
    	    for(int j=0; j<n; j++){
    	        if(ar[j] & (1<<i))
    	            ct2++;
    	        else
    	            ct1++;
    	    }
    	    long long int p = ct1*ct2;
    	    res += (1<<i)*p;
    	}
    	return res;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends