//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int x=0, y=0;
        int a=0, b=0, c=0, d=0;
        for(auto ch:s){
            if(ch=='L')
                y--;
            if(ch=='R')
                y++;
            if(ch=='U')
                x++;
            if(ch=='D')
                x--;
            a = max(a,x);
            b = max(b,y);
            c = min(c,x);
            d = min(d,y);
        }
        if((a-c+1)<=n && (b-d+1)<=m)
            return true;
        else
            return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends