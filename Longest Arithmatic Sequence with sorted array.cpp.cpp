// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
         if(n<=2)
         return n;
         
         int maxlength=2;
         
        int dp[n][n];
         
        for(int i=0;i<n;i++){
            dp[i][n-1]=2;
        }
         
        
         for(int j=n-2;j>0;j--){
             int i=j-1,k=j+1;
             while(i>=0 && k<n){
                 if(A[i]+A[k]==2*A[j]){
                     dp[i][j]=dp[j][k]+1;
                     maxlength=max(maxlength,dp[i][j]);
                     i--;
                     k++;
                 }else if(A[i]+A[k]< 2*A[j]){
                     k++;
                 }else{
                     dp[i][j]=2;//since we are changing the value of i so we are populating that cell since we might further have to refer it
                     i--;
                     
                 }
             }
             
            while(i>=0){
                dp[i][j]=2;
                i--;
            }
         }
          return maxlength;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends