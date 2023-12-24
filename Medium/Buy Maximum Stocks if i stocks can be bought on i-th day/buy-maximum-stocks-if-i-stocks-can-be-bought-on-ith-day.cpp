//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
         vector<pair<int,int>> vp;
      for(int i=0;i<n;i++)
          vp.push_back({price[i],i+1});
      sort(vp.begin(), vp.end());
      int i=0,c=0;
      while(k>=0)
      {
          int t=vp[i].second;
          while(t--)
          {
            k-=vp[i].first;
            c++;
            if(k==0) return c;
            if(k<0) return c-1;
          }
          i++;
      }
      return 0;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends