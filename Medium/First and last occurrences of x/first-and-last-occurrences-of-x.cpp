//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int ft=-1,lt=-1;
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]<=x)
            {
                lt=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        l=0;
        h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]>=x)
            {
                ft=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        vector<int>ans={-1,-1};
        if(arr[ft]!=x || arr[lt]!=x)
        {
            return ans;
        }
        else{
            ans[0]=ft;
            ans[1]=lt;
            return ans;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends