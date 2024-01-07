//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solve(int mid,int arr[],int N,int K)
    {
        int c=1;
        int val=0;
        for(int i=0;i<N;i++)
        {
            val+=arr[i];
            if(val>mid)
            {
                c++;
                val=arr[i];
            }
        }
        return c<=K;
    }
    int splitArray(int arr[] ,int N, int K)
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        int l=*max_element(arr,arr+N);
        int h=sum;
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(solve(mid,arr,N,K))
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends