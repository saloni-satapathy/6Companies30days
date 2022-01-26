// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	   int sum=0;
	   for(int i=0;i<n;i++)
	    sum+=arr[i];
	    
	    int dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;i++)
	      dp[i][0]=1;
	    for(int i=1;i<=sum;i++)
	      dp[0][i]=0;
	    
	    for(int i=1;i<=n;i++){
	         for(int j=1;j<=sum;j++){
	             if(arr[i-1]>j){//index will be one less
	                 dp[i][j]=dp[i-1][j];
	             }else{
	                 if(dp[i-1][j]==1 )
	                  dp[i][j]=1;
	                 else if(dp[i-1][j-arr[i-1]]==1)
	                    dp[i][j]=1;
	                 else
	                    dp[i][j]=dp[i-1][j];
	                 
	             }
	         }
	    }
	     int mindiff=INT_MAX;
	       
	    for(int i=0;i<=sum/2;++i){
	      int first=i;
	      int second=sum-i;
	        if(dp[n][i]==1 && mindiff >abs(first-second)){
	            mindiff= abs(first-second);
	            
	        }
	    }
	     return mindiff;
	    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
