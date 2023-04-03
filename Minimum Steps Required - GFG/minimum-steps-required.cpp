//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int l=str.length();
    int ct=0;
    char prev='\0';
    for(int i=0; i<l; i++){
        char ch = str[i];
        if(ch!=prev){
            ct++;
            prev = ch;
        }
    }
    return ct/2 +1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends