//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    #define ll long long int
    ll findSubarray(vector<ll> &ar, int n ) {
        //code here
        map<ll, ll> mp;
        ll ct=0, curr=0;
        for(ll i=0; i<n; i++){
            curr += ar[i];
            if(curr==0)
                ct++;
            if(mp.find(curr)!=mp.end())
                ct += mp[curr];
            mp[curr]++;
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends