//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       stack<int>st;
       vector<int>ans(n);
       ans[0]=1;
       st.push(0);
       for(int i=1;i<n;i++)
       {
           if(arr[i]<arr[st.top()])
           {
               st.push(i);
               ans[i]=1;
           }
           else{
               int fg=0;
               while(!st.empty())
               {
                   if(arr[st.top()]>arr[i])
                   {
                       ans[i]=i-st.top();
                       st.push(i);
                       fg=1;
                       break;
                   }
                   else{
                       st.pop();
                   }
               }
               if(fg==0)
               {
                   st.push(i);
                   ans[i]=i+1;
               }
           }
       }
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends