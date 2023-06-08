//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j)
        {
            if(arr[i]+arr[j]==sum)
            {
                ans++;
                i++;
                j--;
            }
            else if(arr[i]+arr[j]<sum)
            {
                i++;
            }
            else if(arr[i]+arr[j]>sum)
            {
                j--;
            }
        }
        if(ans==0)
        {
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends