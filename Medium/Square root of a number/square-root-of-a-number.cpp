//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        int l=1;
        int h=x;
        while(l<=h)
        {
            int mid=(l+h)/2;
            long long int t=mid*mid;
            if(t==x)
            {
                return mid;
            }
            if(t<x)
            {
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return floor(sqrt(x));
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends