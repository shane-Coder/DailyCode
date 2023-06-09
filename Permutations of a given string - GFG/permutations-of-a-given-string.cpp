//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string>res;
		    sort(s.begin(), s.end());
		    string v = s;
		    res.push_back(v);
		    while(true){
		        std::next_permutation(v.begin(), v.end());
		        if(v==s)    break;
		        res.push_back(v);
		    }
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends