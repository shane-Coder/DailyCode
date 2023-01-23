//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> st;
        for(auto ch:s){
            if(!st.empty() && st.top()==ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string v;
        while(!st.empty()){
            v += st.top();
            st.pop();
        }
        if(v.size()==0)
            return "-1";
        reverse(v.begin(), v.end());
        return v;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends