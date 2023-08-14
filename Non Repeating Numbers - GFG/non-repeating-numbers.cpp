//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n=nums.size();
        int take=0;
        for(int i=0; i<n; i++){
            take = take^nums[i];
        }
        int start = take & ~(take-1);
        int same=0, diff=0;
        for(int i=0; i<n; i++){
            if(nums[i] & start)
                same = same^nums[i];
            else
                diff = diff^nums[i];
        }
        return {min(same, diff), max(same, diff)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends