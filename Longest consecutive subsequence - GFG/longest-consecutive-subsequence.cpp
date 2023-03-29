//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      vector<int>v;
      for(int i=0;i<N;i++)
      {
          v.push_back(arr[i]);
      }
      sort(v.begin(),v.end());
      int prev=INT_MIN;
      int ans=0;
      int c=0;
      for(int i=0;i<N;i++)
      {
          if(prev==v[i])
          {
              continue;
          }
          else if(prev==(v[i]-1))
          {
              c++;
              prev=v[i];
          }
          else{
              ans=max(ans,c);
              c=1;
              prev=v[i];
          }
      }
      ans=max(ans,c);
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends