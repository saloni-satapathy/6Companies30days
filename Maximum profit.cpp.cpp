// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>>dp(K+1,vector<int>(N));
        for(int i=0;i<N;i++){
            dp[0][1]=0;
        }
         for(int i=0;i<K+1;i++){
             dp[i][0]=0;
         }
         int k;
        for(int i=1;i<K+1;i++){
            for(int j=1;j<N;j++){
                dp[i][j]=dp[i][j-1];
                k=j-1;
                while(k>=0){
                    dp[i][j]=(dp[i][j]>dp[i-1][k]+A[j]-A[k])?dp[i][j]:dp[i-1][k]+A[j]-A[k];
                    k--;
                }
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends