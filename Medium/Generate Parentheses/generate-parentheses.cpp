//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int i,int n,string s,vector<string>&ans,int c)
    {
        if(c<0)
        {
            return;
        }
        if(s.length()==n)
        {
            if(c==0)
            {
                ans.push_back(s);
            }
            return;
        }
        if(c==0)
        {
            s.push_back('(');
            c++;
            solve(i+1,n,s,ans,c);
        }
        else{
            s.push_back(')');
            c--;
            solve(i+1,n,s,ans,c);
            s.pop_back();
            c++;
            s.push_back('(');
            c++;
            solve(i+1,n,s,ans,c);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string s="(";
        vector<string>ans;
        int c=1;
        solve(1,n*2,s,ans,c);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends