//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int min=-1,max=-1;
    map<int,int>mp;
    int l=0,h=n-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]<x)
        {
            l=mid+1;
        }
        else if(arr[mid]>x)
        {
            h=mid-1;
        }
        else{
            min=mid;
            h=mid-1;
        }
    }
    l=0;
    h=n-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]<x)
        {
            l=mid+1;
        }
        else if(arr[mid]>x)
        {
            h=mid-1;
        }
        else{
            max=mid;
            l=mid+1;
        }
    }
    vector<int>ans;
    ans.push_back(min);
    ans.push_back(max);
    return ans;
}

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
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends