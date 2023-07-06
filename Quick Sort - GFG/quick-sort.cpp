//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int ar[], int low, int high)
    {
        // code here
        if(low<high){
            int pivot = partition(ar, low, high);
            quickSort(ar, low, pivot-1);
            quickSort(ar, pivot+1, high);
        }
    }
    
    public:
    int partition (int ar[], int low, int high)
    {
       // Your code here
       int pivot=high, k=low;
       for(int i=low; i<high; i++){
           if(ar[i]<ar[pivot]){
               swap(ar[k], ar[i]);
               k++;
           }
       }
       swap(ar[k], ar[high]);
       return k;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends