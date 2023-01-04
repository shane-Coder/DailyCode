//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        string res;
        set<string> s;
        for(int i=0; i<words.size(); i++)
            s.insert(words[i]);
        sort(words.begin(), words.end());
        for(int i=0; i<words.size(); i++){
            string r=words[i], temp="";
            bool flag = true;
            for(int j=0; j<r.length(); j++){
                temp += r[j];
                if(s.find(temp)==s.end()){
                    flag = false;
                    break;
                }
            }
            if(flag && r.length()>res.length())
                res = r;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends