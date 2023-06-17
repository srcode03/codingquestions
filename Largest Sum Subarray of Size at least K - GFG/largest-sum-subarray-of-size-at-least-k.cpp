//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
   int i=0;
   int j=0;
   int sum=0;
   int ans=INT_MIN;
   int last=0;
   while(i<n && j<n)
   {
       sum=sum+a[j];
       if(j-i+1<k)
       {
           j++;
       }
       else if(j-i+1==k)
       {
           ans=max(ans,sum);
           j++;
       }
       else if(j-i+1>k)
       {
           ans=max(ans,sum);
           last+=a[i];
           i++;
           if(last<0)
           {
               sum-=last;
               ans=max(ans,sum);
               last=0;;
           }
            j++;
       }

   }
   return ans;
}