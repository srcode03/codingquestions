//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int s)
    {
        // Your code here
        stack<int>next;
        stack<int>prev;
        vector<int>n;
        vector<int>p;
        n.push_back(s-1);
        next.push(s-1);
        for(int i=s-2;i>=0;i--)
        {
            int fg=0;
            while(!next.empty())
            {
                if(arr[next.top()]>=arr[i])
                {
                    next.pop();
                }
                else{
                    n.push_back(next.top()-1);
                    next.push(i);
                    fg=1;
                    break;
                }
            }
            if(fg==0)
            {
                n.push_back(s-1);
                next.push(i);
            }
        }
        reverse(n.begin(),n.end());
        p.push_back(0);
        prev.push(0);
        for(int i=1;i<s;i++)
        {
            int fg=0;
            while(!prev.empty())
            {
                if(arr[prev.top()]>=arr[i])
                {
                    prev.pop();
                }
                else{
                    p.push_back(prev.top()+1);
                    prev.push(i);
                    fg=1;
                    break;
                }
            }
            if(fg==0)
            {
                p.push_back(0);
                prev.push(i);
            }
        }
        long long maxi=INT_MIN;
        for(int i=0;i<s;i++)
        {
            maxi=max(arr[i]*(n[i]-p[i]+1),maxi);
        }
        return maxi;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends