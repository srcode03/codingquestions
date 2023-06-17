//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    vector<int>tp;
    for(int i=1;i<n;i++)
    {
        if(a[i]-a[i-1]>1)
        {
            for(int j=a[i-1]+1;j<a[i];j++)
            {
                tp.push_back(j);
            }
        }
    }
    if(tp.size()<k)
    {
        return -1;
    }
    return tp[k-1];
    
}