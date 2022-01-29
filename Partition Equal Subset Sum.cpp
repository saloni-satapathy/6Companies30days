// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
         for(int i=0;i< N;i++){
             sum+=arr[i];
         }
         if(sum%2!=0)
         return 0;
         
         vector<vector<bool>>dp(N+1,vector<bool>(sum+1));
         for(int i=0;i<=sum;i++){
             dp[0][i]=false;
         }
          for(int i=1;i<=N;i++){
              dp[i][0]=true;
          }
          
          for(int i=1;i<=N;i++){
              for(int j=1;j<=sum;j++){
                  if(j<arr[i-1]){
                      
                  }else{
                      if(dp[i-1][j]==true){
                        dp[i][j]=true;  
                      }else{
                          
                          if(dp[i-1][j-arr[i-1]])
                           dp[i][j]=true;
                          else
                           dp[i][j]=false;
                          
                      }
                  }
              }
          }
        return  dp[N][sum/2]?1:0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends