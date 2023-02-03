//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int i=0, j=0;
        int m=matrix.size(), n=matrix[0].size();
        int d=0;
        int first, second;
        while(i>=0 && j>=0 && i<m && j<n){
            if(matrix[i][j]==1){
                d = (d+1)%4;
                matrix[i][j] = 0;
            }
            first = i, second = j;
            if(d==0)
                j++;
            else if(d==1)
                i++;
            else if(d==2)
                j--;
            else
                i--;
        }
        return {first,second};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends