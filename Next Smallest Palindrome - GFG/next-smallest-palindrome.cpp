//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    if(n==1 && num[0]==9)   return {1,1};
	    bool flag=false;
	    for(int i=0; i<n/2; i++){
	        if(num[n-1-i]>num[i])
	            flag = false;
	        else if(num[n-1-i]<num[i])
	            flag = true;
	        num[n-1-i] = num[i];
	    }
	    vector<int>temp;
	    for(int i=0; i<n; i++){
	        temp.push_back(num[i]);
	    }
	    if(flag)    return temp;
	    int carry = 1;
	    for(int i=(n-1)/2; i>=0; i--){
	        temp[i] += carry;
	        if(temp[i]==10){
	            carry = 1;
	        }
	        else{
	            carry = 0;
	        }
	        temp[i] = temp[i]%10;
	        temp[n-1-i] = temp[i];
	    }
	    vector<int>res;
	    if(carry==1){
	        res.push_back(1);
	    }
	    for(int i=0; i<n; i++){
	        res.push_back(temp[i]);
	    }
	    if(carry==1){
	        res[res.size()-1] = 1;
	    }
	    return res;
	    
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends