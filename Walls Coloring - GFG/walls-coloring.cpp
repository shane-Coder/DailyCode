//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
        int pink=0, black=0, yellow=0;
        for(int i=0; i<n; i++){
            int curr_p = min(black, yellow) + colors[i][0];
            int curr_b = min(yellow, pink) + colors[i][1];
            int curr_y = min(pink, black) + colors[i][2];
            pink = curr_p;
            black = curr_b;
            yellow = curr_y;
        }
        return min(pink, min(black, yellow));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends