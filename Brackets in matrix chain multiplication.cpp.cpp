// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

void Parenthesis(int i, int j, int n, int* bracket,
                      char& name,string &s)
{
    if (i == j) {
        
        s+=name;
        name++;
        return;
    }
    s +="(";

    Parenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name,s);

    
    Parenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name, s);
    s+=")";
   
}
    string matrixChainOrder(int p[], int n){
        // code hereint bracket[n-1][n-1];
       
    int bracket[n-1][n-1];
    int dp[n-1][n-1];
    for(int g=0;g<n-1;g++){
      for(int i=0,j=g;j<n-1;i++,j++){
        if(g==0){
              dp[i][j]=0;
        }else if(g==1){
             dp[i][j]=p[i]*p[i+1]*p[j+1];
             bracket[i][j]=i;
        }else{
           int  minVal=INT_MAX;
          int a=0;
      for(int k=i;k<j;k++){
        int lc=dp[i][k];
        int rc=dp[k+1][j];
        int m=p[i]*p[k+1]*p[j+1];
        int total=lc+rc+m;
        if(minVal>total){
           a=k;
        }

        minVal=min(minVal,total);
      }
    
      dp[i][j]=minVal;
      bracket[i][j]=a;
     
        }

      }
    }

char name='A';

string s;
 Parenthesis(0, n - 2, n-1, (int*)bracket, name,s);

return s;
   
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends