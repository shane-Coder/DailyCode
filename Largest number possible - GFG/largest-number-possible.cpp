//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
        string res="";
        if(s==0 && n!=1)
            return "-1";
        for(int i=0; i<n; i++){
            if(s<9){
                res += to_string(s);
                s = 0;
            }
            else{
                res += '9';
                s -= 9;
            }
        }
        if(s!=0)
            return "-1";
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends