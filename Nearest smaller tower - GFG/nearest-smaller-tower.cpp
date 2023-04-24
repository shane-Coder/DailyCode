//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> ar)
    {
        // code here
        int m=*min_element(ar.begin(), ar.end());
        int n=ar.size();
        bool find=false, flag=false, seen=false;
        int l,r;
        vector<int>res(n);
        for(int i=0; i<n; i++){
            if(ar[i]==m)
                res[i] = -1;
        }
        for(int i=0; i<n; i++){
            int j=i-1, k=i+1;
            if(res[i]==-1)
                continue;
            while(j>=0 || k<n){
                find=false, flag=false, seen=false;
                if(j>=0 && ar[j]<ar[i]){
                    l = ar[j];
                    find = true;
                }
                if(k<n && ar[k]<ar[i]){
                    r = ar[k];
                    flag = true;
                }
                if(find==false && flag==false && k>n && ar[j]==ar[i]){
                    res[i] = res[j];
                    seen = true;
                    break;
                }
                else if(find==true && flag==true){
                    if(l<r)
                        res[i] = j;
                    else if(r<l)
                        res[i] = k;
                    else
                        res[i] = j;
                    seen = true;
                    break;
                }
                else if(find==true){
                    res[i] = j;
                    seen = true;
                    break;
                }
                else if(flag==true){
                    res[i] = k;
                    seen = true;
                    break;
                }
                if(j>=0) j--;
                if(k<n) k++;
            }
            if(find==false && flag==false && seen==false)
                res[i] = -1;
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends