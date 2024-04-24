//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
    {
        int arr[x+1][y+1];
        
        for(int i = x; i >= 0; i --){
            
            for(int j = y; j >= 0; j --){
                
                if( i+1 > x || j+1 > y ) arr[i][j] = 1;
                
                else arr[i][j] = (arr[i+1][j] + arr[i][j+1]) % 1000000007;
                
            }
            
        }
        
        return arr[0][0];
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends