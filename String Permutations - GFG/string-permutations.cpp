//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void permute(string&s, vector<string>&v, int i=0){
        if(i==s.length()-1){
            v.push_back(s);
            return ;
        }
        for(int j=i; j<s.length(); j++){
            swap(s[i], s[j]);
            permute(s, v, i+1);
            swap(s[j], s[i]);
        }
    }
    
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string>v;
        permute(s,v);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends