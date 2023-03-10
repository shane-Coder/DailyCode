//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long ar[], int n)
    {
    	// Complete the function
    	long long a=LLONG_MIN, b=LLONG_MIN, c=LLONG_MIN, d=LLONG_MAX, e=LLONG_MAX;
    	for(int i=0; i<n; i++){
    	    long long temp = ar[i];
    	    if(temp>a){
    	        c = b;
    	        b = a;
    	        a = temp;
    	    }
    	    else if(temp>b){
    	        c = b;
    	        b = temp;
    	    }
    	    else if(temp>c){
    	        c = temp;
    	    }
    	    if(temp<d){
    	        e = d;
    	        d = temp;
    	    }
    	    else if(temp<e){
    	        e = temp;
    	    }
    	}
    	if(d!=LLONG_MAX && e!=LLONG_MAX){
    	    return max(a*b*c, a*d*e);
    	}
    	return a*b*c;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends