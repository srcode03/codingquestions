//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        vector<int>ot(n);
        vector<int>in(n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    st.push({i,j});
                }
            }
        }
        while(!st.empty())
        {
            auto it=st.top();
            st.pop();
            ot[it.second]++;
            in[it.first]++;
        }
        for(int i=0;i<n;i++)
        {
            if(ot[i]==n-1 && in[i]==0)
            {
                return i;
            }
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends