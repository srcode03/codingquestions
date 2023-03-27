//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isposs(int mid,int M,int A[],int N)
    {
        int p=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]>mid)
            {
                return false;
            }
            if(sum+A[i]>mid)
            {
                p++;
                sum=A[i];
            }
            else{
                sum=sum+A[i];
            }
        }
        if(p<=M)
        {
            return true;
        }
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N)
        {
            return -1;
        }
        int sum=0;
        int mini=INT_MAX;
        int ans=-1;
        for(int i=0;i<N;i++)
        {
            sum=sum+A[i];
            mini=min(mini,A[i]);
        }
        int s=mini;
        int e=sum;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(isposs(mid,M,A,N))
            {
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends