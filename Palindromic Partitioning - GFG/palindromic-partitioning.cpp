//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPal(string&s, int i, int j){
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        // code here
        int l=str.length();
        int t[l+1] = {0};
        t[l] = 0;
        for(int i=l-1; i>=0; i--){
            int m = INT_MAX;
            for(int j=i; j<l; j++){
                if(isPal(str, i, j)){
                    int temp = 1+t[j+1];
                    m = min(m, temp);
                }
                t[i] = m;
            }
        }
        return t[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends