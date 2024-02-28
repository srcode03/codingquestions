//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution{
    public:
    int DivisibleByEight(string s)
    {
        //code here
        int n=s.length();
        int num=0;
        int a=1;
        for(int i=s.length()-1;i>s.length()-4;i--)
        {
            num+=(s[i]-'0')*a;
            a*=10;
        }
        if(num%8==0)
        {
            return 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends