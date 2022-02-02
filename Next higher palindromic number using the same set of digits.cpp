// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        
        int n=N.length();
         if(n<=3) return "-1";
        int mid= n/2 - 1;
         int i,j;
        for( i=mid-1;i>=0;i--){
            if(N[i]+'0'<N[i+1]+'0')
                break;
            
        }
        if(i<0)return "-1";
        
        int smallest=i+1;
        for( j=i+2;j<=mid;j++){
            if(N[j]+'0'<=N[smallest]+'0' && N[i]+'0'<N[j]+'0'){
                smallest=j;
            }
        }
         
        swap(N[i],N[smallest]);
        swap(N[n-i-1],N[n-smallest-1]);
        
        reverse(N.begin()+i+1,N.begin()+mid+1);
        if(n%2==0){
            reverse(N.begin()+mid+1,N.begin()+n-i-1);
        }else{
            reverse(N.begin()+mid+2,N.begin()+n-i-1);
        }
        
        return N;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends