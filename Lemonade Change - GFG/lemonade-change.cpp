//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        int f=0, t=0;
        for(int i=0; i<n; i++){
            if(bills[i]==20){
                if(t && f){
                    t--;
                    f--;
                }
                else if(f>=3)
                    f -= 3;
                else
                    return false;
            }
            else if(bills[i]==10){
                t++;
                if(f)   f--;
                else    return false;
            }
            else    f++;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends