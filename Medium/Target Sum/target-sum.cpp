//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>&A,int target,int i)
    {
       
        if(i==A.size()){
            return target==0;
        }
        return solve(A,target-A[i],i+1)+solve(A,target+A[i],i+1);
    }
    
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
         return solve(A,target,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends