//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n, vector<string> &ar){
        // Code here
        unordered_map<string,int>mp;
        for(auto str:ar){
            mp[str]++;
        }
        for(int i=0; i<n; i++){
            string str=ar[i];
            string rev=ar[i];
            reverse(rev.begin(),rev.end());
            if(mp[str]!=mp[rev]){
                if(str!=rev)
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends