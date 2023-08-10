//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<string>ans;
    void solve(int o,int z,string op,int N)
    {
        if(op.size()==N)
        {
            ans.push_back(op);
            return;
        }
        if(o!=0)
        {
            string op1=op;
            op1.push_back('1');
            solve(o-1,z,op1,N);
        }
        if(z>o)
        {
            string op1=op;
            op1.push_back('0');
            solve(o,z-1,op1,N);
        }
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    int o=N;
	    int z=N;
	    string op;
	    solve(o,z,op,N);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends