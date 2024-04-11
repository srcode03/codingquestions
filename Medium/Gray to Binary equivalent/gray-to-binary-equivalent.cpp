//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        // Your code here
        int x=log2(n);
        string s;
        for(int i=x;i>=0;i--)
        {
            if(((1<<i)&n))
            {
                s.push_back('1');
            }
            else{
                s.push_back('0');
            }
        }
        string g;
        g.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                if(g[i-1]=='1')
                {
                    g.push_back('0');
                }
                else{
                    g.push_back('1');
                }
            }
            else{
                g.push_back(g[i-1]);
            }
        }
        int ans=0;
        int a=1;
        for(int i=g.length()-1;i>=0;i--)
        {
            if(g[i]=='1')
            {
                ans+=a;
            }
            a*=2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends