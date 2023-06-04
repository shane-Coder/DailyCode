//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        //code here.
        string rev="";
        int i=0;
        stack<string>st;
        while(i<s.length()){
            string temp="";
            while(i<s.length() && s[i]>='0' && s[i]<='9')
                temp += s[i++];
            if(temp!=""){
                st.push(temp);
                temp = "";
            }
            if(i<s.length()){
                string v = "";
                v += s[i];
                st.push(v);
            }
            i++;
        }
        while(!st.empty()){
            rev += st.top();
            st.pop();
        }
        return rev;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends