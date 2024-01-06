//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int sumOfPowers(int a, int b){
	    int ans=0;
	    vector<int> prime(b+1,1);
	    prime[0]=prime[1]=0;
	    for(int i=2;i*i<=b;i++){
	        if(prime[i]==1){
	            for(int j=i*i;j<=b;j+=i)
	                prime[j]=i;
	        }
	    }
	    for(int i=2;i<=b;i++)
	        if(prime[i]==1)
	            prime[i]=i;
	    for(int i=a;i<=b;i++){
	        int val=i;
	        while(val>1){
	            val/=prime[val];
	            ans++;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends