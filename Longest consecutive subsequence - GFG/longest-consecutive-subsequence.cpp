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
      map<int,int>mp;
      for(int i=0;i<N;i++)
      {
          mp[arr[i]]++;
      }
      int prev=INT_MIN;
      int c=1;
      int ans=0;
      for(auto it:mp)
      {
          if(prev==it.first-1)
          {
              c++;
              prev=it.first;
          }
          else{
              ans=max(ans,c);
              c=1;
              prev=it.first;
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