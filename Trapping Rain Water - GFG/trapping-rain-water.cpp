//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
        int s=n;
       vector<int>l(s);
       vector<int>r(s);
       int maxi=INT_MIN;
       for(int i=0;i<s;i++)
       {
           maxi=max(maxi,height[i]);
           l[i]=maxi;
       }
       maxi=INT_MIN;
       for(int i=s-1;i>=0;i--)
       {
           maxi=max(maxi,height[i]);
           r[i]=maxi;
       }
       long long int ans=0;
       for(int i=0;i<s;i++)
       {
           ans=ans+min(l[i],r[i])-height[i];
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends