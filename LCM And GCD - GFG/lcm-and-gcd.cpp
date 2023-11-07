//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int gcd(long long int a,long long int b)
    {
        if(a==0)
        {
            return b;
        }
        return gcd(b%a,a);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long int a;
        if(B>A)
        {
            a=gcd(B,A);    
        }
        else{
            a=gcd(A,B);
        }
        
        long long int b=(A*B)/a;
        vector<long long>ans={b,a};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends