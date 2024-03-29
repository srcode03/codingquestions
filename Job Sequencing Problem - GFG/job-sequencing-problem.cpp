//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job &a,Job &b)
    {
        if(a.profit==b.profit)
        {
            return a.dead<b.dead;
        }
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        vector<int>vis(n+1,0);
        int c=0;
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(vis[arr[i].dead]==1)
            {
                int t=arr[i].dead;
                for(int j=t;j>=1;j--)
                {
                    if(vis[j]==0)
                    {
                        vis[j]=1;
                        p+=arr[i].profit;
                        c++;
                        break;
                    }
                }
            }
            else{
                vis[arr[i].dead]=1;
                p+=arr[i].profit;
                c++;
            }
        }
       vector<int>ans={c,p};
       return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends